/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_skip_isr(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_00011106 == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x1f2,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar1 = (uint)DAT_00011104;
  while( true ) {
    if (DAT_00011106 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00010662. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_modules_funcs_p + 0x2b0))(0x200,*(code **)(_r_modules_funcs_p + 0x2b0));
      return;
    }
    if (DAT_00011105 == uVar1) break;
    iVar3 = uVar1 * 0x10;
    if (((&g_bt_plf_log_level)[iVar3] != '\0') &&
       (iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc)),
       (*(ushort *)(iVar2 + iVar3) >> 3 & 7) == 6)) {
      if (*(code **)(&r_modules_funcs_p + iVar3) == (code *)0x0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x207,*(code **)(_r_plf_funcs_p + 8));
      }
      else {
        (**(code **)(&r_modules_funcs_p + iVar3))
                  (*(undefined4 *)(&sch_prog_env + iVar3),*(undefined4 *)(&r_ip_funcs_p + iVar3),4);
      }
      if (DAT_00011104 == uVar1) {
        DAT_00011104 = (byte)(uVar1 + 1) & 0xf;
      }
      (&g_bt_plf_log_level)[iVar3] = 0;
      DAT_00011106 = DAT_00011106 + -1;
    }
    uVar1 = uVar1 + 1 & 0xf;
  }
  if (DAT_00011106 == '\x01') {
    DAT_00011105 = DAT_00011104 + 1 & 0xf;
  }
  return;
}

