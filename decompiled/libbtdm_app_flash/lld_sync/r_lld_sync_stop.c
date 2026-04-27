/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_sync_stop(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_sync_env + param_1 * 4);
  uVar1 = 0xc;
  if (iVar2 != 0) {
    r_ble_log_internal_x1
              (0x40050163,
               (uint)*(ushort *)(iVar2 + 0x4a) | param_1 << 0x10 |
               (uint)*(byte *)(iVar2 + 0x5b) << 0x18);
    if (*(char *)(iVar2 + 0x5b) == '\0') {
      r_sch_arb_remove(iVar2,0);
      r_lld_sync_cleanup(param_1,0);
      uVar1 = 0;
    }
    else {
      if (*(char *)(iVar2 + 0x5b) == '\x01') {
        *(undefined1 *)(iVar2 + 0x5b) = 2;
      }
      uVar1 = 0;
    }
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

