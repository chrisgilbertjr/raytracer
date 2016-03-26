
#ifndef RAYTRACER_API_H
#define RAYTRACER_API_H

/// Core
#include "Core\Array.h"
#include "Core\Color.h"
#include "Core\MathUtils.h"

/// BRDF's
#include "BRDFs\BRDF.h"
#include "BRDFs\CookTorranceSpecular.h"
#include "BRDFs\GlossySpecular.h"
#include "BRDFs\Lambertian.h"
#include "BRDFs\PerfectSpecular.h"
#include "BRDFs\ShadeRecord.h"

/// Cameras
#include "Cameras\Camera.h"
#include "Cameras\Fisheye.h"
#include "Cameras\Ortho.h"
#include "Cameras\Pinhole.h"
#include "Cameras\Spherical.h"
#include "Cameras\StereoCamera.h"
#include "Cameras\ThinLens.h"

/// Lights
#include "Lights\Light.h"
#include "Lights\AmbientLight.h"
#include "Lights\AmbientOccluder.h"
#include "Lights\AreaLight.h"
#include "Lights\DirectionalLight.h"
#include "Lights\EnvironmentLight.h"
#include "Lights\PointLight.h"

/// Materials
#include "Materials\Material.h"
#include "Materials\Matte.h"
#include "Materials\Phong.h"
#include "Materials\CookTorrance.h"
#include "Materials\Reflective.h"
#include "Materials\Emmisive.h"
#include "Materials\Glossy.h"

/// Objects
#include "Objects\Object.h"
#include "Objects\Plane.h"
#include "Objects\Sphere.h"
#include "Objects\Rectangle.h"
#include "Objects\Cylinder.h"
#include "Objects\CompoundObject.h"
#include "Objects\LightObject.h"
#include "Objects\ConcaveSphere.h"
#include "Objects\SphereLight.h"

/// tracers
#include "Raytracers\Raytracer.h"
#include "Raytracers\PureColor.h"
#include "Raytracers\Shaded.h"
#include "Raytracers\Whitted.h"
#include "Raytracers\AreaLighting.h"
#include "Raytracers\PathTracer.h"

/// Samplers
#include "Samplers\Sampler.h"
#include "Samplers\Simple.h"
#include "Samplers\Hammersley.h"
#include "Samplers\Jittered.h"
#include "Samplers\MultiJittered.h"
#include "Samplers\NRooks.h"
#include "Samplers\PureRandom.h"

/// Textures
#include "Textures\Texture.h"
#include "Textures\Checker2D.h"
#include "Textures\Grid.h"

/// World
#include "World\World.h"
#include "World\ViewingPlane.h"
#include "World\Output.h"
#include "World\ColorBuffer.h"
#include "World\Bitmap.h"

#endif