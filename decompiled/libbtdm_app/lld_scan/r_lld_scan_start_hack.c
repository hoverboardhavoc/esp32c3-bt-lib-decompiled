/*
 * Last changed at upstream commit 3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * https://github.com/espressif/esp32c3-bt-lib/commit/3b0038690a644498d6d80f1de8df0efff8cd8cf5
 * Upstream date: 2022-08-11 21:28:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(f2e5d813)
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
  if (iVar3 == 0) {
    if (g_qa_test_config != '\0') {
      _DAT_60031124 = 0x10001;
      _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | 1;
    }
    if (_lld_scan_env != (int *)0x0) {
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
  }
  return iVar3;
}

