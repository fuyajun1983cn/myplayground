"     _____       __   __     _             
"    |  ___|   _  \ \ / /_ _ (_)_   _ _ __  
"    | |_ | | | |  \ V / _` || | | | | '_ \ 
"    |  _|| |_| |   | | (_| || | |_| | | | |
"    |_|   \__,_|   |_|\__,_|/ |\__,_|_| |_|
"                          |__/   
"    Email: fuyajun1983cn@163.com
"*************全局变量设置***************************************"
let g:isWindows=0

if (has("win32") || has("win64"))
    let g:isWindows=1
endif

let g:isGUI=0
if has("gui_running")
    let g:isGUI=1
endif


"**********************Bundle Plugins******************************"
" Plugins {{{
set nocompatible
syntax on
filetype off "暂时取消文件类型检查
if g:isWindows 
    set rtp+=$VIM/vimfiles/bundle/Vundle.vim
    let path='$VIM/vimfiles/bundle'
    call vundle#begin(path)
else 
    set rtp+=~/.vim/bundle/Vundle.vim
    call vundle#begin()
endif

"Let Vundle manage Vundel, required
"
Plugin 'gmarik/Vundle.vim'

Plugin 'suan/vim-instant-markdown.git'
Plugin 'scrooloose/nerdtree.git'
Plugin 'OmniCppComplete'
Plugin 'octol/vim-cpp-enhanced-highlight'
if g:isGUI
Plugin 'bling/vim-airline'
endif
"Plugin 'chriskempson/tomorrow-theme',{'rtp':'vim'}
Plugin 'tpope/vim-markdown'
"------SnipMate-------------"
Plugin 'MarcWeber/vim-addon-mw-utils'
Plugin 'tomtom/tlib_vim'
Plugin 'garbas/vim-snipmate'
" Optional:
Plugin 'honza/vim-snippets'
Plugin 'tpope/vim-surround'
"------SnipMate------------"
"VIM-GRADLE
Plugin 'tfnico/vim-gradle'
Plugin 'easymotion/vim-easymotion'

Plugin 'google/vim-colorscheme-primary'
"快速管理文件和Buffer
Plugin 'LustyExplorer'
Plugin 'LustyJuggler'
"SuperTab, 在插入模式下按tab键弹出自动提示窗口
Plugin 'ervandew/supertab' 
"Python IDE
"Plugin 'klen/python-mode'
Plugin 'davidhalter/jedi-vim'
"conky
Plugin 'file:///home/fuyajun/.vim/conky'

call vundle#end()
"}}}
filetype plugin indent on



"***********************Basic Settings**************************"
"Start{{{
"取消备份
set nobackup
set noswapfile
set textwidth=80
set nu
set incsearch
set hlsearch
set ignorecase
set smartcase
set laststatus=2 "问题显示状态栏
set hidden "useful for argdo and bufdo
"autocomplete
set completeopt=longest,menuone

"缩进相关设置
set smartindent "启用智能对齐方式
set expandtab "将tab键转换为空格
set tabstop=4 "设置tab键的宽度
set shiftwidth=4 " 执行自动缩进的宽度
set smarttab "指定按一次backspace键就删除shiftwidth宽度


" 解决中文乱码
set encoding=utf-8
set fileencodings=utf-8,chinese,gbk,latin-1,gb2312,ucs-bom,cp936
if g:isWindows
set fileencoding=chinese
else
set fileencoding=utf-8
endif

if g:isGUI
" 解决菜单乱码
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
" 解决consle输出乱码
language messages zh_CN.utf-8
"去掉Scrollbar
set guioptions-=r
endif

set foldenable "Turn on folding
set foldmethod=marker "Fold on the marker
set foldlevel=100 "Don't autofold anything(but I can still fold manually)
set foldopen=block,hor,mark,percent,quickfix,tag "what movements open folds

" 当文件在外部被修改，自动更新该文件
set autoread

"set the mapleader
let mapleader=','
let maplocalleader='\'
let timeoutlen=500 "time to wait for a command

if g:isGUI
set background=dark
colorscheme primary "选择配色方案
else
set t_Co=256
set background=light
colorscheme primary
endif

"Source the vimrc after saving it
autocmd BufWritePost $MYVIMRC source $MYVIMRC
"Fast edit the .vimrc file using ,e
nnoremap <leader>e :tabedit $MYVIMRC<CR>
"END}}}
"
"************************特定格式文件配置**********************"
"Start{{{
" Markdown
augroup ft_markdown
autocmd!
" Use <localLeader>1/2/3/4/5/6 to add headings
autocmd filetype markdown nnoremap <buffer> <LocalLeader>d ^I&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>1 I# <ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>2 I## <ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>3 I### <ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>4 I#### <ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>5 I##### <ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>6 I###### <ESC>
" Use <LocalLeader>b to add blockquotes in normal and visual mode
autocmd filetype markdown nnoremap <buffer> <LocalLeader>b I> <ESC>
autocmd filetype markdown vnoremap <buffer> <LocalLeader>b :s/^/> /<CR>
" Use <localLeader>ul and <localLeader>ol to add list symbols in visual mode
autocmd filetype markdown vnoremap <buffer> <LocalLeader>ul :s/^/* /<CR>
autocmd filetype markdown vnoremap <buffer> <LocalLeader>ol :s/^/\=(line(".")-line("'<")+1).'. '/<CR>
" Use <localLeader>e1/2/3 to add emphasis symbols
autocmd filetype markdown nnoremap <buffer> <LocalLeader>e1 I*<ESC>A*<ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>e2 I**<ESC>A**<ESC>
autocmd filetype markdown nnoremap <buffer> <LocalLeader>e3 I***<ESC>A***<ESC>
autocmd filetype markdown vnoremap <buffer> <LocalLeader>e1 :s/\%V\(.*\)\%V/\*\1\*/<CR>
autocmd filetype markdown vnoremap <buffer> <LocalLeader>e2 :s/\%V\(.*\)\%V/\*\*\1\*\*/<CR>
autocmd filetype markdown vnoremap <buffer> <LocalLeader>e3 :s/\%V\(.*\)\%V/\*\*\*\1\*\*\*/<CR>
" Turn on spell
autocmd filetype markdown setlocal spell
augroup END
"End}}}

"***********************Key Mappings***************************"
"Start{{{
"
inoremap jk <esc>
inoremap <esc> <Nop>

"ban the arrow keys
noremap <Up> <Nop>
noremap <Down> <Nop>
noremap <Right> <Nop>
noremap <Left> <Nop>

nnoremap j gj
nnoremap k gk

"clipboard setting
nnoremap <Leader>p "+p
nnoremap <Leader>P "+P
vnoremap <Leader>y "+y
vnoremap <Leader>p "+p
vnoremap <Leader>P "+p

"NERDTree Setting
map <C-n> :NERDTreeToggle<CR>

"END }}}


"********************Plugin Settings*************************"
"START{{{
"vim-airline
let g:airline_powerline_fonts=1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#left_sep = ' '
let g:airline#extensions#tabline#left_alt_sep = '|'

"NerdTree的配置信息{
"autocmd vimenter * NERDTree "open a NERDTree automatically when vim starts up
"open a NERDTree automatically when vim starts up if no files were specified
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif

"close vim if the only window left open is a NERDTree
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | endif
"}

"OmnicppComplete的配置信息{
noremap<C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>
set tags+=/home/fuyajun/MyPlayground/tags/cpptags
set tags+=/home/fuyajun/MyPlayground/tags/glibctags
"set tags+=/home/fuyajun/MyPlayground/tags/qtbasetags

let OmniCpp_DefaultNamespaces=["std"]
let OmniCpp_MayCompleteDot = 1  ".
let OmniCpp_MayCompleteArrow = 1 "->
let OmniCpp_MayCompleteScope = 1 "::
let OmniCpp_SelectFirstItem = 0

"vim-cpp-enhanced-higlight
let g:cpp_class_scope_highlight = 1
let g:cpp_experimental_template_highlight = 1

"Better navigating through omnicomplete option list
function! OmniPopup(action)
if pumvisible()
    if a:action == 'j'
        return "\<C-N>"
    elseif a:action == 'k'
        return "\<C-P>"
    endif
endif
return a:action
endfunction

inoremap <silent>j <C-R>=OmniPopup('j')<CR>
inoremap <silent>k <C-R>=OmniPopup('k')<CR>


"Setting for jedi-vim
let g:jedi#usages_command = "<leader>z"
let g:jedi#popup_on_dot = 0
let g:jedi#popup_select_first = 0
map <Leader>b Oimport ipdb; ipdb.set_trace() # BREAKPOINT<C-c>
