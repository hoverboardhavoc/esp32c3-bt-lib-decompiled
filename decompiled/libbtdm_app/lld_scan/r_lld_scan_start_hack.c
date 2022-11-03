/*
 * Last changed at upstream commit 976ca00e43905df9e910b400a9e17c311b085ce2
 * https://github.com/espressif/esp32c3-bt-lib/commit/976ca00e43905df9e910b400a9e17c311b085ce2
 * Upstream date: 2022-11-03 19:06:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ef8a115a) - Added config to disable scan backoff - Fixed llm_scan.c assert at line 1485 during controller deinit if duplicate scan is not stopped - Call pll track in controller task
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
    if (g_qa_test_config == '\0') {
      iVar4 = sdk_config_get_opts_ext();
      if (*(short *)(iVar4 + 0x14) != 0) {
        _DAT_60031124 = 0x10001;
        iVar4 = sdk_config_get_opts_ext();
        uVar1 = *(ushort *)(iVar4 + 0x14);
        if ((uVar1 & 0xfe00) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x29ed,*(code **)(_r_plf_funcs_p + 8));
        }
        _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | (uint)uVar1;
      }
    }
    else {
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

