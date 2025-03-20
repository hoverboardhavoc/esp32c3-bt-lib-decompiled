/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_sync_stop(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_sync_env + param_1 * 4);
  uVar2 = 0xc;
  if (iVar1 != 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar3 + 0x28) & 0x80) != 0) {
      iVar3 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar3 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x40020001,
                   (uint)*(ushort *)(iVar1 + 0x4a) << 0x10 | (uint)*(byte *)(iVar1 + 0x5b) << 8 |
                   param_1);
      }
    }
    if (*(char *)(iVar1 + 0x5b) == '\0') {
      r_sch_arb_remove(iVar1,0);
      r_lld_sync_cleanup(param_1,0);
    }
    else if (*(char *)(iVar1 + 0x5b) == '\x01') {
      *(undefined1 *)(iVar1 + 0x5b) = 2;
    }
    uVar2 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar2;
}

