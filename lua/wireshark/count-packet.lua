-- This program will register a menu that will open a window with a count of occurrences
-- of every address in the capture

local function menuable_tap()
        -- Declare the window we will use
        local tw = TextWindow.new("Address Counter")

        -- This will contain a hash of counters of appearances of a certain address
        local ips = {}

        -- this is our tap
        local tap = Listener.new();

        function remove()
                -- this way we remove the listener that otherwise will remain running indefinitely
                tap:remove();
        end

        -- we tell the window to call the remove() function when closed
        tw:set_atclose(remove)

        -- this function will be called once for each packet
        function tap.packet(pinfo,tvb)
                local src = ips[tostring(pinfo.src)] or 0
                local dst = ips[tostring(pinfo.dst)] or 0

                ips[tostring(pinfo.src)] = src + 1
                ips[tostring(pinfo.dst)] = dst + 1
        end

        -- this function will be called once every few seconds to update our window
        function tap.draw(t)
                tw:clear()
                for ip,num in pairs(ips) do
                        tw:append(ip .. "\t" .. num .. "\n");
                end
        end

        -- this function will be called whenever a reset is needed
        -- e.g. when reloading the capture file
        function tap.reset()
                tw:clear()
                ips = {}
        end
end

-- using this function we register our function
-- to be called when the user selects the Tools->Test->Packets menu
register_menu("Test/Packets", menuable_tap, MENU_TOOLS_UNSORTED)