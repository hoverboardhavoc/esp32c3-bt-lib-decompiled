/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_rx_isr(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (uint)DAT_00011104 * 0x10;
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar1 + iVar2) >> 3 & 6) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x17a,*(code **)(_r_plf_funcs_p + 8));
  }
  if (DAT_00011106 == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x17e,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((&g_bt_plf_log_level)[iVar2] == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x181,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(code **)(&r_modules_funcs_p + iVar2) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001048c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(&r_modules_funcs_p + iVar2))
              (*(undefined4 *)(&sch_prog_env + iVar2),*(undefined4 *)(&r_ip_funcs_p + iVar2),2);
    return;
  }
  return;
}

