/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_isr(int param_1)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  undefined2 uVar7;
  
  iVar3 = _lld_test_env;
  if (_lld_test_env == 0) {
    uVar5 = 0x21b;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(_lld_test_env,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    bVar1 = DAT_00011025;
    if (*(char *)(iVar3 + 0x2a) == '\x02') {
      puVar2 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x20a,0,0xff,4,*(code **)(_r_modules_funcs_p + 200));
      *puVar2 = 0;
      uVar7 = 0;
      if (*(char *)(iVar3 + 0x26) == '\0') {
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar7 = *(undefined2 *)(iVar3 + 0x4a);
      }
      *(undefined2 *)(puVar2 + 2) = uVar7;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2,*(code **)(_r_modules_funcs_p + 0xe0));
                    /* WARNING: Could not recover jumptable at 0x00010532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 500))(1);
      return;
    }
    cVar6 = DAT_00011024;
    if (param_1 != 0) {
      cVar6 = *(char *)(iVar3 + 0x16) + DAT_00011025;
    }
    *(char *)(iVar3 + 0x16) = cVar6;
    *(ushort *)(iVar3 + 0x14) = bVar1 & 0xf | 0x6000;
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar3,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar4 == 0) {
      *(undefined1 *)(iVar3 + 0x2a) = 0;
      return;
    }
    uVar5 = 0x215;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
                    /* WARNING: Could not recover jumptable at 0x000105a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0,"lld_test.c",uVar5);
  return;
}

