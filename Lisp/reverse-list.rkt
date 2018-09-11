#lang racket
(define (reverse items)
  (define (reverse-iter remain result)
    (if (null? remain)
        result
        (reverse-iter (cdr remain)
                      (cons (car remain) result))))
  (reverse-iter items '()))

(reverse (list 1 4 9 16 25))