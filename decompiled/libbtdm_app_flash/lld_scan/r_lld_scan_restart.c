/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_scan_restart(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0xc;
  if (_lld_scan_env != 0) {
    uVar2 = 0;
    while( true ) {
      iVar1 = *(int *)(_lld_scan_env + uVar2 * 4);
      if (iVar1 != 0) {
        iVar3 = r_sdk_config_get_opts_ext(iVar3);
        if (((*(uint *)(iVar3 + 0x28) & 8) != 0) &&
           (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
          iVar3 = r_ble_log_internal_x1
                            (0x40010003,
                             (uint)*(byte *)(iVar1 + 0x3e) << 0x10 |
                             (uint)*(byte *)(iVar1 + 0x3c) << 8 | uVar2);
        }
        if ((((*(char *)(iVar1 + 0x3c) == '\0') &&
             (iVar3 = r_lld_read_clock(), *(char *)(iVar1 + 0x3e) != '\x01')) &&
            (uVar4 = *(int *)(iVar1 + 4) - iVar3 & 0xfffffff, uVar4 < 0x8000001)) && (0x3c < uVar4))
        {
          r_sch_arb_remove(iVar1,0);
          *(int *)(iVar1 + 4) = iVar3;
          iVar3 = r_sch_arb_insert(iVar1);
        }
      }
      if (uVar2 == 1) break;
      uVar2 = 1;
    }
    iVar3 = 0;
  }
  return iVar3;
}

