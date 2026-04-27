/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> ke_msg.o -> r_ke_msg_send_basic
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_msg_send_basic(void)

{
  int iVar1;
  
  iVar1 = r_ke_msg_alloc(0);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_co_list_push_back(&ke_env,iVar1 + -0xc);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  r_ble_log_internal_x2
            (0x404a0237,CONCAT22(*(undefined2 *)(iVar1 + -2),*(undefined2 *)(iVar1 + -8)),
             CONCAT22(*(undefined2 *)(iVar1 + -6),*(undefined2 *)(iVar1 + -4)));
  r_ke_event_set(3);
  return;
}

