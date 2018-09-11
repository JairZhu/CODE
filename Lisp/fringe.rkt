#lang racket
(define (fringe tree)
  (cond ((null? tree) '())
        ((not (pair? tree)) (list tree))
        (else (append (fringe (car tree))
              (fringe (cadr tree))))))

(define x (list (list 1 2) (list 3 4)))
x
(fringe x)
