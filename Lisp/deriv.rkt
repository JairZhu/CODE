#lang racket
(define (deriv g)
  (lambda (x)
    (/ (- (g (+ x dx)) (g x))
       dx)))
(define dx 0.000001)

(define (cube x) (* x x x))

((deriv cube) 5)