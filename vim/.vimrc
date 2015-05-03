set nocompatible
syntax on
filetype off
set rtp+=~/.vim/bundle/Vundle.vim/
call vundle#begin()
"\\\\\\\\\\\\\\\\\\\\1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
" plugins Settings
"
Plugin 'gmarik/Vundle.vim'

"Markdown
"
Plugin 'godlygeek/tabular'
Plugin 'plasticboy/vim-markdown'
Plugin 'swaroopch/vim-markdown-preview'
Plugin 'vimwiki'
Plugin 'snipmate'
Plugin 'omnicppcomplete'
"Plugin 'autocomplpop'

call vundle#end()
filetype plugin indent on

"setting for omnifunc
"
nnoremap <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>
set completeopt=menu,menuone
let OmniCpp_ShowPrototypeInAbbr=1
let OmniCpp_MayCompleteScope=1
let OmniCpp_NamespaceSearch=1
let OmniCpp_GlobalScopeSearch=1
"let OmniCpp_DefaultNamespace=["std"]
let OmniCpp_SelectFirstItem=2
set tags+=/usr/include/c++/tags

"
"setting for autocomplpop
"
let g:acp_ignorecaseOption=1
"let g:acp_mappingDrive=1
let g:acp_behaviorKeywordCommand="\<C-x>\<C-o>"
let g:acp_behaviorSnipmateLength=1
"\\\\\\\\\\\\\\\\\\\\2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
"###########BASIC SETTING#######################
"set leader key
"
:let mapleader="-"

:iab #d #define
:iab #i #include
:iabbrev @@ yajun.fu@163.com
:iabbrev ccopy Copyright 2015 Yajun Fu, all rights reserved
:set shiftwidth=4
:set hlsearch
:set incsearch
:set textwidth=70 "a 70 column page


"\\\\\\\\\\\\\\\\\\\\3\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
"key mapping Settings
"
"%% short for %:h<Tab>
"
cnoremap <expr> %% getcmdtype() == ':' ? expand('%:h').'/' : '%%'

"ban the arrow key
"
noremap <Up> <Nop>
noremap <Down> <Nop>
noremap <Left> <Nop>
noremap <Right> <Nop>
inoremap <esc> <Nop>

"keymapping
"
inoremap <c-u> <esc>viwU
inoremap jk <esc>

nnoremap <leader>ev :vsplit $MYVIMRC<cr>
"add a double quotoes for a word in current cursor
"
noremap <leader>" viw<esc>a"<esc>hbi"<esc>lel

"\\\\\\\\\\\\\\\\\\\\4\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
"################Global Variable Settings###############
"no folding for markdown
"
let g:vim_markdown_folding_disabled = 1


"\\\\\\\\\\\\\\\\\\\\5\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
"###########FileType specific settings
" add comments short key for current line
"
:autocmd FileType python nnoremap <buffer> <localleader>c I#<esc>


"adding folding capabilities for vim --------------------{{{

augroup filetype_vim
    autocmd!
    autocmd FileType vim setlocal foldmethod=marker
augroup END
" }}}
"


"\\\\\\\\\\\\\\\\\\\\6\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
"##############Status LIne Settings##############3333333
"

