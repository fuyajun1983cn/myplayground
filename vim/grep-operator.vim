nnoremap <leader>g :set operatorfunc=<SID>GrepOperator<cr>g@
vnoremap <leader>g :<c-u>call <SID>GrepOperator(visualmode())<cr>

function! s:GrepOperator(type) "s:将当前函数的名字空间限制到当前脚本的范围
    let saved_unnamed_register=@@ "操作前保存之前的操作内容

    if a:type ==# 'v' "case-sensitive comparision
        execute "normal! `<v`>y"
    elseif a:type ==# 'char'
        execute "normal! `[v`]y"
    else
        return
    endif

    silent execute "grep! -R " .  shellescape(@@) . " ."
    copen

    let @@=saved_unnamed_register "恢复之前保存的操作内容

endfunction
