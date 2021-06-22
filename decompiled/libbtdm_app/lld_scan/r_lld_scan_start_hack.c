/*
 * Last changed at upstream commit 4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b93865b52ab92f0b7777ed415b6598b96ac1d6d
 * Upstream date: 2021-06-22 22:28:01 +0800
 * Upstream subject: Update ESP32-C3/ESP32-S3 bt-lib (e6e17bb4)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_start_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_scan_start_hack(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = r_lld_scan_start();
  if ((iVar3 == 0) && (_lld_scan_env != (int *)0x0)) {
    piVar6 = _lld_scan_env + 2;
    piVar2 = _lld_scan_env;
    do {
      if (*piVar2 != 0) {
        iVar5 = (uint)*(byte *)(*piVar2 + 0x38) * 0x5a;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar1 = *(ushort *)(iVar4 + iVar5);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar4 + iVar5) = uVar1 & 0xffdf;
      }
      piVar2 = piVar2 + 1;
    } while (piVar6 != piVar2);
  }
  return iVar3;
}

