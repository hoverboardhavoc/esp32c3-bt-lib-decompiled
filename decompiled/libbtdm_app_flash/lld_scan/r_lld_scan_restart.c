/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_restart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_scan_restart(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = 0xc;
  if (_lld_scan_env != 0) {
    uVar2 = 0;
    while( true ) {
      iVar1 = *(int *)(_lld_scan_env + uVar2 * 4);
      if (iVar1 != 0) {
        r_ble_log_internal_x1
                  (0x400100c7,
                   (uint)*(byte *)(iVar1 + 0x3c) << 8 | (uint)*(byte *)(iVar1 + 0x3e) << 0x10 |
                   uVar2);
        if ((((*(char *)(iVar1 + 0x3c) == '\0') &&
             (iVar4 = r_lld_read_clock(), *(char *)(iVar1 + 0x3e) != '\x01')) &&
            (uVar5 = *(int *)(iVar1 + 4) - iVar4 & 0xfffffff, uVar5 < 0x8000001)) && (0x3c < uVar5))
        {
          r_sch_arb_remove(iVar1,0);
          *(int *)(iVar1 + 4) = iVar4;
          r_sch_arb_insert(iVar1);
        }
      }
      if (uVar2 == 1) break;
      uVar2 = 1;
    }
    uVar3 = 0;
  }
  return uVar3;
}

