/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> ke_msg.o -> r_ke_msg_forward
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_msg_forward(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + -6) = param_2;
  *(undefined2 *)(param_1 + -4) = param_3;
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_co_list_push_back(&ke_env,param_1 + -0xc);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  r_ble_log_internal_x2
            (0x404a020c,CONCAT22(*(undefined2 *)(param_1 + -2),*(undefined2 *)(param_1 + -8)),
             CONCAT22(*(undefined2 *)(param_1 + -6),*(undefined2 *)(param_1 + -4)));
  r_ke_event_set(3);
  return;
}

