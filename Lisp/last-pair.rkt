#lang racket
(define (last-pair items)
  (if (= (length items) 1)
      items
      (last-pair (cdr items))))

(last-pair (list 23 72 149 34))
