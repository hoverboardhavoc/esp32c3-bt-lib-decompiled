/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_end_isr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_end_isr_handler(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  
  uVar1 = (uint)DAT_00011104;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = uVar1 * 0x10;
  uVar4 = *(ushort *)(iVar2 + iVar5) >> 3 & 7;
  if (DAT_00011106 == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0xbb,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((&g_bt_plf_log_level)[iVar5] == '\0') {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar4,uVar1,"sch_prog.c",0xbe,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if ((uVar4 - 3 & 0xff) < 3) {
    if (*(code **)(&r_modules_funcs_p + iVar5) == (code *)0x0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0xd8,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      (**(code **)(&r_modules_funcs_p + iVar5))
                (*(undefined4 *)(&sch_prog_env + iVar5),*(undefined4 *)(&r_ip_funcs_p + iVar5),
                 uVar4 == 4);
    }
    uVar3 = (uint)DAT_00011105;
    DAT_00011106 = DAT_00011106 + -1;
    (&g_bt_plf_log_level)[iVar5] = 0;
    do {
      if (uVar3 == uVar1) break;
      uVar1 = uVar1 + 1 & 0xf;
    } while ((&g_bt_plf_log_level)[uVar1 * 0x10] == '\0');
    DAT_00011104 = (byte)uVar1;
  }
  if (DAT_00011106 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00010100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x2b0))(0x200);
    return;
  }
  return;
}

