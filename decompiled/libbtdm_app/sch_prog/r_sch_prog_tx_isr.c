/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_tx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_tx_isr(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (uint)DAT_00011104 * 0x10;
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar1 + iVar2) >> 3 & 6) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x19f,*(code **)(_r_plf_funcs_p + 8));
  }
  if (DAT_00011106 == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x1a3,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((&g_bt_plf_log_level)[iVar2] == '\0') {
    (**(code **)(_r_plf_funcs_p + 8))(0,"sch_prog.c",0x1a6,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(code **)(&r_modules_funcs_p + iVar2) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010542. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(&r_modules_funcs_p + iVar2))
              (*(undefined4 *)(&sch_prog_env + iVar2),*(undefined4 *)(&r_ip_funcs_p + iVar2),3);
    return;
  }
  return;
}

