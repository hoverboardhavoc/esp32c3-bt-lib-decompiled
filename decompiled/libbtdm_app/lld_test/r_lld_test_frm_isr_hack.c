/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_isr_hack(int param_1)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  undefined2 uVar7;
  
  if (_lld_test_env == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x99,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar4 = _lld_test_env;
  _DAT_600310d0 = 0;
  if ((*(char *)(_lld_test_env + 0x2a) == '\x02') && (*(char *)(_lld_test_env + 0x26) == '\x01')) {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(1,*(code **)(_r_ip_funcs_p + 0x6b8));
    puVar3 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x20a,0,0xff,4,*(code **)(_r_modules_funcs_p + 200));
    *puVar3 = 0;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(iVar4 + 0x44);
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
                    /* WARNING: Could not recover jumptable at 0x0001067a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 500))(1);
    return;
  }
  if (_lld_test_env == 0) {
    uVar5 = 0x21b;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 8);
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(_lld_test_env,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    bVar1 = DAT_00011025;
    if (*(char *)(iVar4 + 0x2a) == '\x02') {
      puVar3 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x20a,0,0xff,4,*(code **)(_r_modules_funcs_p + 200));
      *puVar3 = 0;
      uVar7 = 0;
      if (*(char *)(iVar4 + 0x26) == '\0') {
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar7 = *(undefined2 *)(iVar4 + 0x4a);
      }
      *(undefined2 *)(puVar3 + 2) = uVar7;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
                    /* WARNING: Could not recover jumptable at 0x00010532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 500))(1);
      return;
    }
    cVar6 = DAT_00011024;
    if (param_1 != 0) {
      cVar6 = *(char *)(iVar4 + 0x16) + DAT_00011025;
    }
    *(char *)(iVar4 + 0x16) = cVar6;
    *(ushort *)(iVar4 + 0x14) = bVar1 & 0xf | 0x6000;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar4,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar2 == 0) {
      *(undefined1 *)(iVar4 + 0x2a) = 0;
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

