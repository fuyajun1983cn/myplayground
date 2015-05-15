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
if g:isGUI
Plugin 'bling/vim-airline'
endif
Plugin 'chriskempson/tomorrow-theme',{'rtp':'vim'}
Plugin 'tpope/vim-markdown'

call vundle#end()
"}}}
filetype plugin indent on



"***********************Basic Settings**************************"
"Start{{{
"取消备份
set nobackup
set noswapfile
set nu
set incsearch
set hlsearch
set laststatus=2 "问题显示状态栏

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

if g:isGUI
    colorscheme Tomorrow-Night-Bright "选择配色方案
endif

"Source the vimrc after saving it
autocmd BufWritePost $MYVIMRC source $MYVIMRC
"END}}}
"
"************************特定格式文件配置**********************"
"Start{{{

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
