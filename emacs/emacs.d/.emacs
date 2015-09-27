;;close startup page
(setq inhibit-startup-screen t)
;;color-scheme solarized
;;https://github.com/sellout/emacs-color-theme-solarized.git
(add-to-list 'custom-theme-load-path "~/MyPlayground/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-color-theme-solarized")
;(load-theme 'solarized t)

;;color-scheme gruvbox
;;https://github.com/greduan/emacs-theme-gruvbox.git
(add-to-list 'custom-theme-load-path "~/MyPlayground/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-theme-gruvbox")
(load-theme 'gruvbox t)
