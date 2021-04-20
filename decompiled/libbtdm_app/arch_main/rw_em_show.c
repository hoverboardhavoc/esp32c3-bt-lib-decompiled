/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> arch_main.o -> rw_em_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rw_em_show(void)

{
  if (2 < _g_bt_plf_log_level) {
    ets_printf("EM_ET_OFFSET: 0x%08x, EM_ET_END: 0x%08x\n",0,0x100);
    if (2 < _g_bt_plf_log_level) {
      ets_printf("EM_FT_OFFSET: 0x%08x, EM_FT_END: 0x%08x\n",0x100,0x128);
      if (2 < _g_bt_plf_log_level) {
        ets_printf("EM_RF_SW_SPI_OFFSET: 0x%08x, EM_RF_SW_SPI_END: 0x%08x\n",0x128,0x128);
        if (2 < _g_bt_plf_log_level) {
          ets_printf("EM_RF_SW_SPI_OFFSET: 0x%08x, EM_RF_SW_SPI_END: 0x%08x\n",0x128,0x128);
          if (2 < _g_bt_plf_log_level) {
            ets_printf("EM_RF_SW_SPI_OFFSET: 0x%08x, EM_RF_SW_SPI_END: 0x%08x\n",0x128,0x128);
            if (2 < _g_bt_plf_log_level) {
              ets_printf("EM_RF_HW_SPI_OFFSET: 0x%08x, EM_RF_HW_SPI_END: 0x%08x\n",0x128,0x128);
              if (2 < _g_bt_plf_log_level) {
                ets_printf("EM_RF_HW_SPI_OFFSET: 0x%08x, EM_RF_HW_SPI_END: 0x%08x\n",0x128,0x128);
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("EM_RF_HW_SPI_OFFSET: 0x%08x, EM_RF_HW_SPI_END: 0x%08x\n",0x128,0x128);
                  if (2 < _g_bt_plf_log_level) {
                    ets_printf("EM_ENC_OFFSET: 0x%08x, EM_ENC_END: 0x%08x\n",0x128,0x148);
                    if (2 < _g_bt_plf_log_level) {
                      ets_printf("EM_BLE_OFFSET: 0x%08x, EM_BLE_END: 0x%08x\n",0x148,0xcc00);
                      if (2 < _g_bt_plf_log_level) {
                        ets_printf("EM_BLE_CS_OFFSET: 0x%08x, EM_BLE_CS_END: 0x%08x\n",0x400,0x838);
                        if (2 < _g_bt_plf_log_level) {
                          ets_printf("EM_BLE_WL_OFFSET: 0x%08x, EM_BLE_WL_END: 0x%08x\n",0xc00,0xc60
                                    );
                          if (2 < _g_bt_plf_log_level) {
                            ets_printf("EM_BLE_RAL_OFFSET: 0x%08x, EM_BLE_RAL_END: 0x%08x\n",0xc60,
                                       0xe68);
                            if (2 < _g_bt_plf_log_level) {
                              ets_printf("EM_BLE_RX_DESC_OFFSET: 0x%08x, EM_BLE_RX_DESC_END: 0x%08x\n"
                                         ,0x1000,0x10c8);
                              if (2 < _g_bt_plf_log_level) {
                                ets_printf("EM_BLE_TX_DESC_OFFSET: 0x%08x, EM_BLE_TX_DESC_END: 0x%08x\n"
                                           ,0x1400,0x18ec);
                                if (2 < _g_bt_plf_log_level) {
                                  ets_printf("EM_BLE_LLCPTXBUF_OFFSET: 0x%08x, EM_BLE_LLCPTXBUF_END: 0x%08x\n"
                                             ,0x1c00,0x1e1c);
                                  if (2 < _g_bt_plf_log_level) {
                                    ets_printf("EM_BLE_ADVEXTHDRTXBUF_OFFSET: 0x%08x, EM_BLE_ADVEXTHDRTXBUF_END: 0x%08x\n"
                                               ,0x2000,0x22ee);
                                    if (2 < _g_bt_plf_log_level) {
                                      ets_printf("EM_BLE_ADVDATATXBUF_OFFSET: 0x%08x, EM_BLE_ADVDATATXBUF_END: 0x%08x\n"
                                                 ,0x2400,0x7400);
                                      if (2 < _g_bt_plf_log_level) {
                                        ets_printf(
                                                  "EM_BLE_AUXCONNECTREQTXBUF_OFFSET: 0x%08x, EM_BLE_AUXCONNECTREQTXBUF_END: 0x%08x\n"
                                                  ,0x7400,0x7466);
                                        if (2 < _g_bt_plf_log_level) {
                                          ets_printf(
                                                  "EM_BLE_DATARXBUF_OFFSET: 0x%08x, EM_BLE_DATARXBUF_END: 0x%08x\n"
                                                  ,0x7800,0x9c00);
                                          if (2 < _g_bt_plf_log_level) {
                                            ets_printf(
                                                  "EM_BLE_ACLTXBUF_OFFSET: 0x%08x, EM_BLE_ACLTXBUF_END: 0x%08x\n"
                                                  ,0x9c00,0xcc00);
                                            return;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}

