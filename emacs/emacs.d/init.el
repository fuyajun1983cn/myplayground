;;init.el begin
(if (file-readable-p "~/.emacs.d/.emacs") (load "~/.emacs.d/.emacs"))
;;init.el end
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(ansi-color-names-vector ["color-237" "#d75f5f" "#afaf00" "#ffaf00" "#87afaf" "#d787af" "#87af87" "color-223"])
 '(custom-safe-themes (quote ("0788bfa0a0d0471984de6d367bb2358c49b25e393344d2a531e779b6cec260c5" "6998bd3671091820a6930b52aab30b776faea41449b4246fdce14079b3e7d125" "8c75217782ccea7e9f3ad2dae831487a5fb636d042263d0a0e0438d551da3224" "aab598c4d024d544b4e8b356a95ca693afa9de000b154bd2f86eed68c9e75557" "70340909b0f7e75b91e66a02aa3ad61f3106071a1a4e717d5cdabd8087b47ec4" "b869a1353d39ab81b19eb79de40ff3e7bb6eaad705e61f7e4dbdcb183f08c5a6" "b5fe3893c8808466711c1b55bb7e66b9c6aa2a86811783375a43e1beabb1af33" "532769a638787d1196bc22c885e9b85269c3fc650fdecfc45135bb618127034c" "beeb5ac6b65fcccfe434071d4624ff0308b5968bf2f0c01b567d212bcaf66054" "8e7ca85479dab486e15e0119f2948ba7ffcaa0ef161b3facb8103fb06f93b428" "fbcdb6b7890d0ec1708fa21ab08eb0cc16a8b7611bb6517b722eba3891dfc9dd" "e87a2bd5abc8448f8676365692e908b709b93f2d3869c42a4371223aab7d9cf8" "ca8350a6affc43fc36f84a5271e6d5278857185753cd91a899d1f88be062f77b" default)))
 '(org-agenda-files (quote ("~/.document/test.org"))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
(put 'upcase-region 'disabled nil)
(put 'downcase-region 'disabled nil)
(put 'set-goal-column 'disabled nil)
