//
//  ViewController.swift
//  lab3_s4a
//
//  Created by Student on 20/01/2022.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    
    @IBAction func handlePan(_ recognizer:UIPanGestureRecognizer) {
          let translation = recognizer.translation(in: self.view)
          if let view = recognizer.view {
            view.center = CGPoint(x:view.center.x + translation.x,
                                    y:view.center.y + translation.y)}
          recognizer.setTranslation(CGPoint.zero, in: self.view)
    }

}

