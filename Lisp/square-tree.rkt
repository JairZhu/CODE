#lang racket
(define (square-tree tree)
  (map (lambda (subtree)
         (if (pair? subtree)
             (square-tree subtree)
             (* subtree subtree)))
       tree))

(square-tree (list (list 1 2) (list 3 4)))
