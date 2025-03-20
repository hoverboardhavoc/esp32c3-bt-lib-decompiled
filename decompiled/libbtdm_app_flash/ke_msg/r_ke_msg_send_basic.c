/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  int iVar2;
  
  iVar2 = r_ke_msg_alloc(0);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  r_co_list_push_back(&ke_env,iVar2 + -0xc);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  iVar1 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar1 + 0x28) & 2) != 0) &&
     (iVar1 = r_sdk_config_get_opts_ext(), *(byte *)(iVar1 + 0x2c) < 3)) {
    r_ble_log_internal_x2
              (0x4045000a,CONCAT22(*(undefined2 *)(iVar2 + -2),*(undefined2 *)(iVar2 + -8)),
               CONCAT22(*(undefined2 *)(iVar2 + -6),*(undefined2 *)(iVar2 + -4)));
  }
  r_ke_event_set(3);
  return;
}

