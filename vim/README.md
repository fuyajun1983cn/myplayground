##Echoing Message  
we should use *echom* in script.  
 you can use *messages* to check *echom* output


##Setting Options
* boolean option 
* set number 
* set nonumber 
* set number! 
* set number?  "Checking option

##Basic Mapping

**any mode:**  

map - x

map <space> viw

map <c-d> dd

####**mapping keys is one of the places where vim comments don't work.**

**normal mode:**

nmap \ dd

**visual mode:**  

vmap \ U

insert mode:

imap <c-d> <esc>ddi

**unset a mapping

nunmap \


nonrecursive mapping : always use nonrecursive variants as possible as we can

nnoremap \ x

inoremap \ x

vnoremap \ x

##Leader key  
* set leader key:
* let mapleader = "-"
* nnoremap <leader>d dd

###set local leader key  
* let maplocalleder = "\\"
* nnoremap <localleader>d dd

##Abbreviations  
abbreviations will be expaned when you type anything that's not a
letter, number or underscore

##Buffer-Local Options and Mappings  
* :nnoremap           <leader>d  dd
* :nnoremap  <buffer> <leader>x  dd

##Set Local Variables  
* :setlocal number


##AutoCommands  
* :autocmd BufNewFile * :write

to see a list of all the events:
* :help autocmd-events  

* :autocmd FileType python :iabbrev <buffer> iff if:<left>


##Grouping Autocommands  
* :augroup testgroup
* :    autocmd!    clear a group
* :    autocmd  BufWrite * :echom "Cats"
* :augroup END

##Operator-Pending Mappings  
dw Delete  to next word  
ci( Change inside parens  
yt, Yank   until comma  
:onoremap p i(  
:onoremap il( :<c-u>normal! F)vi(<cr>  

**normal! doesn't recognize "special characters" link <cr>**  
the easies way to get around it is use **read**  

onoremap ah :<c-u>execute "normal! ?^==\\+\r:nohlsearch\rg_vk0"<cr>  



##Status line  
:set statusline=%f
:set statusline+=\ -\   
:set statusline+=FileType:  
:set statusline+=%y  

##folding capabilites  
augroup filetype_vim  
    autocmd!
    autocmd FileType vim setlocal foldmethod=marker
augroup END


##Variables and Options  
:let foo="bar"  

Options as Variables  
:set textwdith=80  
:echo &textwidth  
:let &textwidth=100  

local options  
:let &l:number=1  

Registers as Variables  
:let @a="hello"
:echo @"

perform a search in your file with /someword,   
:echo @/  
vim will echo the search pattern

##Variables Scoping  
:let b:hello="word"  
:echo b:hello  

##Conditions  
**Multiple-Line Statements**  
:echom "foo" | echom "bar"

:if 1  
:    echom "ONE:  
:endif  


1. VIM will try to coerce variables when necessary. 
2. Strings that start with a number are coerced to that number, otherwise they're coerced to 0
3. Vim will execute the body of an if statement whne its condition evaluates to a non-zero integer,
after all coercion takes place.

:if 0  
:    echom "if"  
:elseif "nope!"  
:    echom "elseif"  
:else  
:    echom "finally"  
:endif  

**Vimscript is case sensitive**  
set ignorecase  
set noignorecase  

Code Sample:  
:set noignorecase  
:if "foo" ==? "FOO"  
:    echom "first"
:elseif "foo" ==? "foo"  
:    echom "second"
:endif

**==?** is "case-insensitive" no matter what the user has set" comparison operator.  
Code Sample:  
:set ignorecase  
:if "foo" ==# "FOO"  
:    echom "one"
:elseif "foo" ==# "foo"  
:    echom "two"  
:endif  

**==#** is the "case-sensitive no matter what the user has set" comparison operator.


##Functions  
**Vimscript functions must start with a capital letter if they are unscoped!**

It's a convention to always capitalize the first letter of function names .

Code Sample:  
:function Meow()  
:    echom "Meow!"  
:endfunction  

:call Meow()  

**if a vimscript function doesn't return a value, it implicitly return 0.**  

Code Sample:  
:function TextwidthIsTooWide()
:    if &l:textwidth ># 80  
:        return 1  
:    endif  
:endfunction  

**up to 26 arguments can be used in a function**

**a function name must be made of alphanumeric characters and '_', and must start with a capital or
"s:"**

##Function Arguments  
:function DisplayName(name)  
:    echom "Hello! My name is :"  
:    echom a:name  
:endfunction

**When you write a Vimscript function that takes arguments you always need to prefix those arguments
with a: when you use them to tell Vim that they're in the argument scope.**

Varargs  
```
:function Varg(...)  
:    echom a:1  
:    echo a:000  
:endfunction  

:call Varg("a", "b")
```

**a:0** will be set to the number of extra arguments you were given.  
**a:000** will be set to a list containig all the extra arguments that were passed.  
```
:function Varg(foo, ...)  
:    echom a:foo  
:    echom a:0  
:    echom a:1  
:    echo a:000  
:endfunction  

:call Varg2("a", "b", "c")
```

**You cann't reassign argument variables**


##Numbers  
echo 3 / 2.0  
Vim will display 1.5

##Strings  
concatenation  
:echom "Hello, " + "world"  
Vim will display 0.

**Vim will not coerce strings to Floats  
:echom 10 + "10.10"  
Vim will display 20

String concatenation operator "."  
:echom "Hello, " . "world"  

:echom 10 . "foo"  
Vim will display 10foo

:echom 10.1 . "foo"  
Vim throws an error. Vim won't let you use a Float as a String when concatenating.  

**Special Characters**  
:echom "foo \"bar\""  

:echo foo\nbar  
Vim will display two lines.  

:echom "foo\nbar"  
Vim will display foo^@bar. ^@ is Vim's way of saying "newline character"

**Literal Strings**  
:echom '\n\\'  
Using single quotes tells Vim that you want the string exactly as-is, with no escape sequences.

**String functions**  
Length  
:echom strlen("foo")  
:echom len("foo")  

Splitting  
:echo split("one two three")  
:echo split("one,two,three",",")  

Joining  
:echo join(["foo", "bar"], "...")  
Vim will display foo...bar

Lower and Upper Case  
:echom tolower("Foo")  
:echom toupper("Foo")  

##Execute  
Basic Execution  
:execute "echom 'Hello, world!'"

##Normal  
Avoiding Mappings  
:normal G  
:normal! G  
normal! tell Vim move to bottom of the file even though G has been mapped.  
**When writing scripts you should always use normal!.**  

Special Characters  
:normal! /foo<cr>  
**normal! doesn't parse special character sequences link <cr>**  

##Execute Normal!  
:execute "normal! gg/foo\<cr>dd"  
normal! cann't parse <cr>, combining execute and normal! will fix the problem.  


##Basic Regular Expressions  
>execute "normal! gg/print\<cr>"  

>execute "normal! G?print\<cr>"  



>/print .\+    
>:execute "normal! gg/for .\\+ in .\\+:\<cr>"  
>:execute 'normal! gg/for .\+ in . \+:\<cr>'   this is has some problem for parsing <cr>  
>:execute "normal! gg" . '/for .\+ in .\+:' . "\<cr>"  


in this mode, with pattern \v, we can use regular expressions in
similar way in other programming language.  
>:execute "normal! gg" . '/\vfor .+ in .+:' . "\<cr>"  



##Case Study: Grep Operator, Part One

>:nnoremap <leader>g :silent execute "grep! -R" . shellescape(expand("<cWORD>")) . " ."<cr>:copen<cr>  


@@ is the "unnamed" register: the one that Vim places text into when you yank or
delete without specify a particular register.


##list    
vimsscript support list has similar operation as other language such as python.  
built-in method:  
* add()
* len()
* get()
* index()
* join()
* reverse()

##loop  
```
:let c=0  
:for i in [1, 2, 3, 4]
:    let c += i  
:endfor

:echom

:let c = 1  
:let total = 0  

:while c <= 4   
:  let total += c  
:  let c += 1  
:endwhile  

:echom total  
```

##Dictionary    
:echo {'a':1, 100: 'foo',}

* get()
* has_key()
* items()
* keys()
* values()


#Toggling    
* toggle a boolean option

```
:nnoremap <leader>N :setlocal number!<cr>
```

* toggle a non-boolean option  
```
nnoremap <leader>f :call FoldColumnToggle()<cr>
function! FoldColumnToggle()
if &foldcolumn
setlocal foldcolumn=0
else
setlocal foldcolumn=4
endif
endfunction
```
* toggle other things  
```
nnoremap <leader>q :call QuickfixToggle()<cr>
let g:quickfix_is_open = 0
function! QuickfixToggle()
if g:quickfix_is_open
cclose
let g:quickfix_is_open = 0
execute g:quickfix_return_to_window . "wincmd w"
else
let g:quickfix_return_to_window = winnr()
copen
let g:quickfix_is_open = 1
endif
endfunction
```

###函数编程   
Vimscript支持使用变量存储函数，但是语法有点怪。
例如：
```
:let Myfunc = function("Append")
:echo Myfunc([1,2],3)
```
**注意，变量名的第一个字母必须是大写。**

函数也可以存储到一个列表中：  
```
:let funcs = [function("Append"), function("Pop")]
:echo funcs[1](['a', 'b', 'c'], 1)
```
这次列表的变量名不需要第一个字母大写，因为它只是一个列表变量。

###路径    
* 绝对路径  
  :echom expand('%') "当前文件的相对路径    
  :echom expand('%:p') "当前文件的绝对路径    
  :echom fnamemodify('foo.txt', ':p')     
  "显示当前目录下的文件foo.txt的绝对路径，不管该文件是否存在    
  :echo globpath('.', '*') "列出指定目录下的文件列表    


###Vim插件的目录结构  
* ~/.vim/colors/  
  color schemes,通常就一行代码    
* ~/.vim/plugin/  
  此目录下的脚本Vim每次启动的时候都会执行一次  
* ~/.vim/ftdetect/  
  此目录下的文件也是每次启动Vim时会执行一次, 该目录下的文件一般设置了一些
  自动命令来检测和设置文件的filetype，一般不超过一行代码。  
  ```
    au BufNewFile,BufRead *.pn set filetype=potion
  ```
* ~/.vim/ftplugin/  
  每次设置Buffer的filetype会被执行，里面一般设置buffer-local的选项。  
* ~/.vim/indent/  
  类似ftplugin目录下的文件，跟特定文件类型相关的代码，设置的选项也是buffer
  local。  
* ~/.vim/compiler/  
  工作方式跟indent一样，基于文件名设置跟编译器相关的选项,这些选项也是buffer
  local的。  
* ~/.vim/after/  
  每次vim启动时会执行，但是晚于~/.vim/plugin/里面的文件。一般需要覆盖Vim默认的选项时，才会
  将在此目录下设备一些选项。
* ~/.vim/autoload/  
  这个目录非常重要。autoload是一个延迟插件加载的方式。  
* ~/.vim/doc/
  放置插件的文档。  
* ~/.vim/syntax/  
  设置关键字，函数等语法加亮  
  ```
  if exists("b:current_syntax")
      finish
  endif

  syntax keyword potionKeyword loop times to while
  syntax keyword potionKeyword if elseif else
  syntax keyword potionKeyword class return

  syntax keyword potionFunction print join string

  syntax match potionComment "\v#.*$"  " \v tell Vim to use "very magic" mode
  syntax match potionOperator "\v\*"
  syntax region potionString start=/\v"/ skip=/\v\\./ end=/\v"/

  highlight link potionKeyword Keyword
  highlight link potionFunction Function
  highlight link potionComment Comment  
  highlight link potionOperator Operator
  highlight link potionString String


  let b:current_syntax = "potion"
  ```

###Basic Folding  
设置fold方法  
>setlocal foldmethod=indent

常用快捷键：
za: 收起或展开大于或等于当前行的foldlevel的所有行
zr/zo: 展开大于或等于当前行的foldlevel的所有行
zR/zO: 展开所有行。
zm: 收起所有行 

foldlevel  
* 每行代码都有一个"foldlevel"，通常是0或是一个整数。-1代表一个特殊的foldlevel，通常是"undefined"，该行的foldlevel取自它的上一行或下一行的foldlevel值小的那个。
* foldlevel为0的行不会包含在任何收起的行中。
* foldlevel相同的相邻行收进在一起。
* 如果foldlevel为X的收起行被收起，所有foldlevel比它大的行都会被收起。 











max = 10
print "Starting"

for i in range(max):
    print "Counter:", i

print "Done"




  that's






w word
i inside
t till







