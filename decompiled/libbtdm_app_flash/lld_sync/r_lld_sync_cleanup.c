/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_sync_cleanup(uint param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (*(int *)(&lld_sync_env + param_1 * 4) != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 0x80) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x40020002,
                   (uint)*(ushort *)(*(int *)(&lld_sync_env + param_1 * 4) + 0x4a) << 0x10 |
                   param_2 << 8 | param_1);
      }
    }
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
    *puVar2 = (char)param_1;
    puVar2[1] = (char)param_2;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_sync_env + param_1 * 4));
    *(undefined4 *)(&lld_sync_env + param_1 * 4) = 0;
  }
  return;
}

