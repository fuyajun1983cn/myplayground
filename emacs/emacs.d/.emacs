;; -*- mode:elisp -*-

;;                                         ;;
;;;;;;;;;;;;;;;;基本配置;;;;;;;;;;;;;;;;;;;;;
;;                                         ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;close startup page
(setq inhibit-startup-message t
inhibit-startup-echo-area-message t)

;;显示行号
(global-linum-mode 1)

;;取消滚动栏
(scroll-bar-mode -1)

;;取消菜单栏
(menu-bar-mode -1)

;;取消工具栏
(tool-bar-mode -1)

;;IDO模式
(ido-mode 1)
(setq ido-enable-flex-matching t)
(setq ido-everything t)

;;设置打开文件的缺省路径
(setq default-directory "~/")

;;*********加载路径设置********
(add-to-list 'load-path "~/.emacs.d/")
(add-to-list 'load-path "~/.emacs.d/mode/evil/")
(add-to-list 'load-path "~/.emacs.d/mode/auto-complete/")
(add-to-list 'load-path "~/.emacs.d/mode/popup")
(add-to-list 'load-path "~/.emacs.d/mode/yasnippet")
(add-to-list 'load-path "e:/mysoft/my-program-wharehouse/emacs/emacs.d/mode/evil")
(add-to-list 'load-path "e:/mysoft/my-program-wharehouse/emacs/emacs.d/mode/auto-complete")
(add-to-list 'load-path "e:/mysoft/my-program-wharehouse/emacs/emacs.d/settings")
(add-to-list 'load-path "~/.emacs.d/settings")

;;设定不产生备份文件
(setq make-backup-files nil)
(setq-default make-backup-files nil)

;;允许emacs和外部其他程序的粘贴
(setq x-select-enable-clipboard t)

;;鼠标中键可以粘贴
(setq mouse-yank-at-point t)

;;设置个人信息
(setq user-full-name "Fu Yajun")
(setq user-mail-address "fuyajun1983cn@163.com")

;;自动在文件末增加一行
(setq require-final-newline t)

;;当光标在行尾上下移动的时候，始终保持在行尾
(setq track-eol t) 

;;***************************************************;;
;;                                                                                                       ;;
;;*******************通用按键配置********************;;
;;                                                                                                       ;;
;;****************************************************;;
;;新行自动缩进
(define-key global-map (kbd "RET") 'newline-and-indent)

;;剪贴板复制和粘贴设置
(global-set-key [f8] 'copy-to-clipboard)
(global-set-key [f9] 'paste-from-clipboard)

;;============================================;;
;;                                            ;;
;;=============颜色方案配置====================;;
;;                                            ;;
;;============================================;;
;;color-scheme solarized
;;https://github.com/sellout/emacs-color-theme-solarized.git
;(add-to-list 'custom-theme-load-path "e:/mysoft/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-color-theme-solarized")
;(add-to-list 'custom-theme-load-path "/cygdrive/e/mysoft/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-color-theme-solarized")
;(load-theme 'solarized t)
;(add-hook 'after-make-frame-functions
;	  (lambda (frame)
;	    (let ((mode (if (display-graphic-p frame) 'light 'dark)))
;	      (set-frame-parameter frame 'background-mode mode)
;	      (set-terminal-parameter frame 'background-mode mode))
;	    (enable-theme 'solarized)))

;;color-scheme gruvbox
;;https://github.com/greduan/emacs-theme-gruvbox.git
(add-to-list 'custom-theme-load-path "e:/mysoft/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-theme-gruvbox")
(add-to-list 'custom-theme-load-path "/cygdrive/e/mysoft/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-theme-gruvbox")
(add-to-list 'custom-theme-load-path "~/.emacs.d/colorscheme/emacs-theme-gruvbox")
(load-theme 'gruvbox t)

;;*********************************************;;
;;                                             ;;
;;**************auto-complete模式相关配置*******;;
;;                                             ;;
;;*********************************************;;
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/mode/auto-complete/dict")
(ac-config-default)
(define-key ac-mode-map (kbd "M-/") 'auto-complete);;auto-complete command
;;trigger auto-complete
;(ac-set-trigger-key "TAB")
(setq ac-auto-start 3);当播入3个字符的时候，开始自动补全
;;complete menu color
(set-face-background 'ac-candidate-face "lightgray")
(set-face-underline 'ac-candidate-face "darkgray")
(set-face-background 'ac-selection-face "steelblue")
;My Dictionary
(add-to-list 'ac-user-dictionary-files "~/.emacs.d/settings/mydic")

;;YASnippet
(require 'yasnippet)
(setq yas-snippet-dirs '("~/.emacs.d/mode/yasnippet/snippets" "~/.emacs.d/mode/yasnippet/yasmate/snippets"))
(yas-global-mode 1)
	

;;*********************************************;;
;;                                             ;;
;;**************Org模式相关配置*****************;;
;;                                             ;;
;;*********************************************;;
(global-set-key "\C-cl" 'org-store-link)
(global-set-key "\C-ca" 'org-agenda)
(global-set-key "\C-cc" 'org-capture)
(global-set-key "\C-cb" 'org-iswitchb)

;;*********************************************;;
;;                                                                                          ;;
;;**************Evil模式相关配置***************;;
;;                                                                                          ;;
;;*********************************************;;
;;变量设定
(setq evil-shift-width 8)

(require 'evil)
(evil-mode 1)

;; esc quits
(defun minibuffer-keyboard-quit ()
  "Abort recursive edit.
In Delete Selection mode, if the mark is active, just deactivate it;
then it takes a second \\[keyboard-quit] to abort the minibuffer."
  (interactive)
  (if (and delete-selection-mode transient-mark-mode mark-active)
      (setq deactivate-mark  t)
    (when (get-buffer "*Completions*") (delete-windows-on "*Completions*"))
    (abort-recursive-edit)))
(define-key evil-normal-state-map [escape] 'keyboard-quit)
(define-key evil-visual-state-map [escape] 'keyboard-quit)
(define-key minibuffer-local-map [escape] 'minibuffer-keyboard-quit)
(define-key minibuffer-local-ns-map [escape] 'minibuffer-keyboard-quit)
(define-key minibuffer-local-completion-map [escape] 'minibuffer-keyboard-quit)
(define-key minibuffer-local-must-match-map [escape] 'minibuffer-keyboard-quit)
(define-key minibuffer-local-isearch-map [escape] 'minibuffer-keyboard-quit)
(global-set-key [escape] 'evil-exit-emacs-state)

;;using "jk" to return to normal mode from insert mode
(require 'key-chord)
(key-chord-mode 1)
(key-chord-define-global "jk" 'evil-normal-state)
