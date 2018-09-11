#lang racket
(define (same-parity sample . others)
  (filter (if (even? sample)
              even?
              odd?)
          (cons sample others)))

(same-parity 1 2 3 5 6 7 8 23 43)