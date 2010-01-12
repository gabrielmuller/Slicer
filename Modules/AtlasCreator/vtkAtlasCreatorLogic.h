/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkAtlasCreatorLogic.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/
#ifndef __vtkAtlasCreatorLogic_h
#define __vtkAtlasCreatorLogic_h

#include "vtkSlicerModuleLogic.h"
#include "vtkMRMLScene.h"

#include "vtkAtlasCreator.h"
#include "vtkMRMLAtlasCreatorNode.h"


class vtkITKGradientAnisotropicDiffusionImageFilter;

class VTK_ATLASCREATOR_EXPORT vtkAtlasCreatorLogic : public vtkSlicerModuleLogic
{
  public:
  static vtkAtlasCreatorLogic *New();
  vtkTypeMacro(vtkAtlasCreatorLogic,vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);

  // TODO: do we need to observe MRML here?
  virtual void ProcessMrmlEvents ( vtkObject *caller, unsigned long event,
                                   void *callData ){};

  // Description: Get/Set MRML node storing parameter values
  vtkGetObjectMacro (AtlasCreatorNode, vtkMRMLAtlasCreatorNode);
  void SetAndObserveAtlasCreatorNode(vtkMRMLAtlasCreatorNode *n) 
    {
    vtkSetAndObserveMRMLNodeMacro( this->AtlasCreatorNode, n);
    }

  // The method that creates and runs VTK or ITK pipeline
  void Apply();
  
protected:
  vtkAtlasCreatorLogic();
  virtual ~vtkAtlasCreatorLogic();
  vtkAtlasCreatorLogic(const vtkAtlasCreatorLogic&);
  void operator=(const vtkAtlasCreatorLogic&);

  vtkMRMLAtlasCreatorNode* AtlasCreatorNode;
  vtkITKGradientAnisotropicDiffusionImageFilter* GradientAnisotropicDiffusionImageFilter;

};

#endif

