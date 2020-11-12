#pragma once

namespace InfernoModManager {

	public ref class SmoothablePictureBox : public System::Windows::Forms::PictureBox
	{
	    public:
            property System::Nullable<System::Drawing::Drawing2D::SmoothingMode> SmoothingMode {
                System::Nullable<System::Drawing::Drawing2D::SmoothingMode> get() { return smoothingMode; }
                System::Void set(System::Nullable<System::Drawing::Drawing2D::SmoothingMode> value) { smoothingMode = value; }
            }

            property System::Nullable<System::Drawing::Drawing2D::CompositingQuality> CompositingQuality {
                System::Nullable<System::Drawing::Drawing2D::CompositingQuality> get() { return compositingQuality; }
                System::Void set(System::Nullable<System::Drawing::Drawing2D::CompositingQuality> value) { compositingQuality = value; }
            }

            property System::Nullable<System::Drawing::Drawing2D::InterpolationMode> InterpolationMode {
                System::Nullable<System::Drawing::Drawing2D::InterpolationMode> get() { return interpolationMode; }
                System::Void set(System::Nullable<System::Drawing::Drawing2D::InterpolationMode> value) { interpolationMode = value; }
            }

	    protected:
            virtual void OnPaint(System::Windows::Forms::PaintEventArgs^ pe) override {
                if (smoothingMode.HasValue)
                    pe->Graphics->SmoothingMode = smoothingMode.Value;
                if (compositingQuality.HasValue)
                    pe->Graphics->CompositingQuality = compositingQuality.Value;
                if (interpolationMode.HasValue)
                    pe->Graphics->InterpolationMode = interpolationMode.Value;

                // this line is needed for .net to draw the contents.
                __super::OnPaint(pe);
            }

	    private:
            System::Nullable<System::Drawing::Drawing2D::SmoothingMode> smoothingMode;
            System::Nullable<System::Drawing::Drawing2D::CompositingQuality> compositingQuality;
            System::Nullable<System::Drawing::Drawing2D::InterpolationMode> interpolationMode;
	};
}
