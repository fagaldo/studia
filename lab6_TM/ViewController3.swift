//
//  ViewController3.swift
//  lab3_s4a
//
//  Created by Student on 20/01/2022.
//

import UIKit

class ViewController3: UIViewController,
                       UIImagePickerControllerDelegate, UINavigationControllerDelegate, UIGestureRecognizerDelegate {

    @IBOutlet weak var imagePicked: UIImageView!
    var newPhoto = false
    
    //metoda podpięta pod przycisk Aparat
    @IBAction func openCameraButton(_ sender: Any) {
      if UIImagePickerController.isSourceTypeAvailable(.camera) {
         let imagePicker = UIImagePickerController()
         imagePicker.delegate = self
         imagePicker.sourceType = .camera
         imagePicker.cameraDevice = .front
         imagePicker.allowsEditing = false
               self.present(imagePicker, animated: true, completion: nil)
               newPhoto = true
          } }
          //metoda podpięta pod przycisk Galeria
          @IBAction func openPhotoLibraryButton(_ sender: Any) {
            if UIImagePickerController.isSourceTypeAvailable(.photoLibrary) {
               let imagePicker = UIImagePickerController()
               imagePicker.delegate = self
               imagePicker.sourceType = .photoLibrary
               imagePicker.allowsEditing = false
               self.present(imagePicker, animated: true, completion: nil)
          } }
          //metoda delegate wywołana po zrobieniu zdjęcia lub wyborze zdjęcia w galerii
          func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
             let image = info[UIImagePickerController.InfoKey.originalImage] as! UIImage
             imagePicked.image = image
             dismiss(animated:true, completion: nil)
             //zapis zdjęcia
             if (newPhoto == true) {
                 UIImageWriteToSavedPhotosAlbum(image, nil, nil, nil)
                 newPhoto = false
          } }
    
    @IBAction func handlePinch(recognizer: UIPinchGestureRecognizer)
    {
        recognizer.view!.transform = recognizer.view!.transform.scaledBy( x: recognizer.scale, y: recognizer.scale)
        recognizer.scale = 1
    }
    @IBAction func handleRotation(recognizer: UIRotationGestureRecognizer)
    {
        recognizer.view!.transform = recognizer.view!.transform.rotated(by: recognizer.rotation)
        recognizer.rotation = 0
    }
    
    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer,
      shouldRecognizeSimultaneouslyWith otherGestureRecognizer: UIGestureRecognizer)
      -> Bool {
    return true }
    override func viewDidLoad() {
        super.viewDidLoad()

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
