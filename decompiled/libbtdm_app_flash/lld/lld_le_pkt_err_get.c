/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld.o -> lld_le_pkt_err_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lld_le_pkt_err_get(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (0xb < param_1) {
    r_assert_param(0xc,"lld.c",0x2bd);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = CONCAT22(*(undefined2 *)(&lld_le_pkt_env + param_1),
                        *(undefined2 *)((int)&lld_le_pkt_env + param_1 * 4 + 2));
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return 0;
}

