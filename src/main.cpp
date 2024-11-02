#include <iostream>

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <google/protobuf/message.h>

extern "C" {
#include <libavcodec/avcodec.h>
}

int main() {
    std::cout << "Hello, FFmpeg, AWS, and Protobuf World!" << std::endl;

    // Use FFmpeg to print codec info (a simple check to verify FFmpeg linkage)
    const AVCodec* codec = avcodec_find_decoder(AV_CODEC_ID_H264);
    if (codec) {
        std::cout << "H264 codec found: " << codec->name << std::endl;
    } else {
        std::cout << "H264 codec not found!" << std::endl;
    }

    // Initialize AWS SDK
    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {
        Aws::Client::ClientConfiguration clientConfig;
        Aws::S3::S3Client s3_client(clientConfig);
        auto outcome = s3_client.ListBuckets();
        if (outcome.IsSuccess()) {
            std::cout << "Buckets:" << std::endl;
            for (const auto& bucket : outcome.GetResult().GetBuckets()) {
                std::cout << "  * " << bucket.GetName() << std::endl;
            }
        } else {
            std::cerr << "Failed to list buckets: " << outcome.GetError().GetMessage() << std::endl;
        }
    }
    Aws::ShutdownAPI(options);

    // Protobuf message demonstration
    google::protobuf::Message* message = nullptr;
    if (message) {
        std::cout << "Protobuf message is initialized." << std::endl;
    } else {
        std::cout << "Protobuf message is null." << std::endl;
    }

    return 0;
}
