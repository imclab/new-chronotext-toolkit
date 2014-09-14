
package org.chronotext.GrapeFrukt;

import org.chronotext.cinder.CinderDelegate;
import org.json.JSONException;
import org.json.JSONObject;

import android.app.Activity;
import android.content.res.Configuration;
import android.graphics.Color;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Button;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.RelativeLayout;

public class Bridge extends CinderDelegate
{
  static
  {
    System.loadLibrary("GrapeFrukt");
  }

  protected RelativeLayout rootView;
  protected RelativeLayout overlayView;

  public Bridge(Activity activity)
  {
    super(activity);

    // ---

    rootView = new RelativeLayout(activity);
    rootView.setBackgroundColor(Color.YELLOW);
    activity.setContentView(rootView);

    rootView.addView(getView());
    getView().setVisibility(View.GONE);

    overlayView = new RelativeLayout(activity);
    activity.addContentView(overlayView, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));

    // ---

    addButton("hide / show", 100, 100, 1);
    addButton("detach / attach", 100, 200, 2);
  }

  void addButton(String text, int x, int y, final int id)
  {
    Button button = new Button(getActivity());
    button.setText(text);
    button.setId(1);

    RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
    params.leftMargin = x;
    params.topMargin = y;
    overlayView.addView(button, params);

    button.setOnClickListener(new OnClickListener()
    {
      @Override
      public void onClick(View v)
      {
        buttonClicked(id);
      }
    });
  }

  void buttonClicked(int id)
  {
    boolean hidden = (getView().getVisibility() != View.VISIBLE);
    boolean detached = (getView().getParent() == null);

    switch (id)
    {
      case 1:
        if (hidden)
        {
          getView().setVisibility(View.VISIBLE);
        }
        else
        {
          getView().setVisibility(View.GONE);
        }
        break;

      case 2:
        if (detached)
        {
          rootView.addView(getView());
        }
        else
        {
          rootView.removeView(getView());
        }
    }
  }
  
  public void handleMessage(Message msg)
  {}
}