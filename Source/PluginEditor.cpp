/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Gain101AudioProcessorEditor::Gain101AudioProcessorEditor (Gain101AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (100, 300);
    
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 20);
    mGainSlider.setRange(-60.0f, 6.0f, 0.01f);
    mGainSlider.setValue(-15.0f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);
    
}

Gain101AudioProcessorEditor::~Gain101AudioProcessorEditor()
{
}

//==============================================================================
void Gain101AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

}

void Gain101AudioProcessorEditor::resized()
{
    mGainSlider.setBounds(getWidth()/2 - 25, getHeight()/2 - 90, 50, 180);
    
}

void Gain101AudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &mGainSlider)
    {
        audioProcessor.mGain = mGainSlider.getValue();
    }
}
