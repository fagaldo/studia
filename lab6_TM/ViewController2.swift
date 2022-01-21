//
//  ViewController2.swift
//  lab3_s4a
//
//  Created by Student on 20/01/2022.
//

import UIKit

class ViewController2: UIViewController {
    
    var timer = Timer()
    var counter = 0
    var timerRunning = false
    var startRecognizer: UITapGestureRecognizer!
    var stopRecognizer: UITapGestureRecognizer!
    var swipeRecognizer: UISwipeGestureRecognizer!
    
    required init(coder aDecoder: NSCoder)
    {
        super.init(coder:aDecoder)!
        startRecognizer = UITapGestureRecognizer(target: self, action: #selector(handleTap))
        stopRecognizer = UITapGestureRecognizer(target: self, action: #selector(handleTap2))
        swipeRecognizer = UISwipeGestureRecognizer(target: self, action: #selector(handleSwipes))
        
    }
    @objc func funkcja_obslugi()
    {
              count.text = String(counter)
              counter += 1
    }
    @objc func handleSwipes(sender: UISwipeGestureRecognizer)
    {
        counter = 0
        count.text = String(counter)
    }
    @objc func handleTap(sender: UITapGestureRecognizer)
    {
        if(!timerRunning)
        {
            timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(funkcja_obslugi), userInfo: nil, repeats: true)
            timerRunning = true
        }
    }
    @objc func handleTap2(sender: UITapGestureRecognizer)
    {
        if(timerRunning)
        {
            timer.invalidate()
            timerRunning = false
        }
    }
    @IBOutlet weak var Label: UILabel!
    
    
    @IBOutlet weak var count: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        stopRecognizer.numberOfTouchesRequired = 2
        swipeRecognizer.numberOfTouchesRequired = 1
        swipeRecognizer.direction = .left
        
        view.addGestureRecognizer(startRecognizer)
        view.addGestureRecognizer(stopRecognizer)
        view.addGestureRecognizer(swipeRecognizer)
        Label.text = "Timer"
        
        // Do any additional setup after loading the view.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
