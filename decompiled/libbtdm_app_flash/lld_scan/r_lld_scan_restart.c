/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0xc;
  if (_lld_scan_env != 0) {
    uVar3 = 0;
    do {
      iVar2 = *(int *)(_lld_scan_env + uVar3 * 4);
      if (iVar2 != 0) {
        iVar4 = r_sdk_config_get_opts_ext(iVar4);
        if ((*(uint *)(iVar4 + 0x28) & 8) != 0) {
          iVar4 = r_sdk_config_get_opts_ext();
          if (*(byte *)(iVar4 + 0x2c) < 3) {
            iVar4 = r_ble_log_internal_x1
                              (0x40010003,
                               (uint)*(byte *)(iVar2 + 0x3e) << 0x10 |
                               (uint)*(byte *)(iVar2 + 0x3c) << 8 | uVar3);
          }
        }
        if (((*(char *)(iVar2 + 0x3c) == '\0') &&
            (iVar4 = r_lld_read_clock(), *(char *)(iVar2 + 0x3e) != '\x01')) &&
           ((*(int *)(iVar2 + 4) - iVar4 & 0xfffffffU) - 0x3d < 0x7ffffc4)) {
          r_sch_arb_remove(iVar2,0);
          *(int *)(iVar2 + 4) = iVar4;
          iVar4 = r_sch_arb_insert(iVar2);
        }
      }
      bVar1 = uVar3 != 1;
      uVar3 = 1;
    } while (bVar1);
    iVar4 = 0;
  }
  return iVar4;
}

