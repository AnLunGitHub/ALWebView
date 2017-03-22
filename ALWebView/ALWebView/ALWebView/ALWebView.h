//
//  ALWebView.h
//  test5
//
//  Created by Work on 2017/3/21.
//  Copyright © 2017年 Work. All rights reserved.
//

#import <UIKit/UIKit.h>
@class ALWebView;
@protocol ALWebViewDelegate <NSObject>
@optional
- (BOOL)webView:(ALWebView *)webView
shouldStartLoadWithRequest:(NSURLRequest *)request
 navigationType:(UIWebViewNavigationType)navigationType;
- (void)webViewDidStartLoad:(ALWebView *)webView;
- (void)webViewDidFinishLoad:(ALWebView *)webView;
- (void)webView:(ALWebView *)webView didFailLoadWithError:(NSError *)error;
@end

//设置js回调block
typedef void (^MPWebViewJavascriptEvaluationCompletionHandler)(id result, NSError *error);

@interface ALWebView : UIView

//初始化，并决定是否UIWebView
- (instancetype)initWithFrame:(CGRect)frame;
@property (weak, nonatomic) id<ALWebViewDelegate> delegate; //设置代理

- (void)loadHTMLString:(NSString *)string //加载html
               baseURL:(NSURL *)baseURL;
- (void)loadRequest:(NSURLRequest *)request; //加载request

@property (nonatomic, readonly, getter=isLoading) BOOL loading; //是否正在加载
@property (nonatomic, readonly) BOOL canGoBack; //是否能后退
@property (nonatomic, readonly) BOOL canGoForward; //是否能前进

- (void)stopLoading; //停止加载
- (void)reload; //重新加载
- (void)goBack; //后退
- (void)goForward; //前进
- (void)evaluateJavaScript:(NSString *)javaScriptString //注入js
         completionHandler:(MPWebViewJavascriptEvaluationCompletionHandler)completionHandler;
@end
