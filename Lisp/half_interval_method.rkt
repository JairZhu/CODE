#lang racket
(define (search f neg pos)
  (let ((mid (/ (+ neg pos) 2)))
    (if (close-enough? neg pos)
        mid
        (let ((test-value (f mid)))
          (cond ((positive? test-value)
                 (search f neg mid))
                ((negative? test-value)
                 (search f mid pos))
                (else mid))))))

(define (abs x) (if (< x 0) (- x) x))

(define (close-enough? x y)
  (< (abs (- x y)) 0.000000001))

(search (lambda (x) (- (* x x x) (* 2 x) 3))
        1.0
        2.0)
