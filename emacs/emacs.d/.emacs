;;                                         ;;
;;;;;;;;;;;;;;;;基本配置;;;;;;;;;;;;;;;;;;;;;
;;                                         ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;close startup page
(setq inhibit-startup-screen t)

;;============================================;;
;;                                            ;;
;;=============颜色方案配置====================;;
;;                                            ;;
;;============================================;;
;;color-scheme solarized
;;https://github.com/sellout/emacs-color-theme-solarized.git
(add-to-list 'custom-theme-load-path "~/MyPlayground/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-color-theme-solarized")
;(load-theme 'solarized t)

;;color-scheme gruvbox
;;https://github.com/greduan/emacs-theme-gruvbox.git
(add-to-list 'custom-theme-load-path "~/MyPlayground/my-program-wharehouse/emacs/emacs.d/colorscheme/emacs-theme-gruvbox")
(load-theme 'gruvbox t)

;;*********************************************;;
;;                                             ;;
;;**************Org模式相关配置*****************;;
;;                                             ;;
;;*********************************************;;
(global-set-key "\C-cl" 'org-store-link)
(global-set-key "\C-ca" 'org-agenda)
(global-set-key "\C-cc" 'org-capture)
(global-set-key "\C-cb" 'org-iswitchb)
