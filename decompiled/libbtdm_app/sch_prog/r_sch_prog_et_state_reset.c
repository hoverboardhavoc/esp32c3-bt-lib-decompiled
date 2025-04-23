/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_et_state_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_et_state_reset(void)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  
  pcVar3 = (char *)(**(code **)(_r_ip_funcs_p + 0x920))(*(code **)(_r_ip_funcs_p + 0x920));
  if (*pcVar3 != '\0') {
    while (DAT_00011106 != '\0') {
      uVar6 = (uint)DAT_00011104;
      iVar2 = uVar6 * 0x10;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar4 + iVar2) >> 3 & 7;
      if (1 < _g_bt_plf_log_level) {
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        ets_printf("et:%d,st:%x\n",uVar6,*(ushort *)(iVar4 + iVar2) >> 3 & 7);
      }
      if (uVar1 < 6) {
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar1 = *(ushort *)(iVar4 + iVar2);
            iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
            *(ushort *)(iVar4 + iVar2) = uVar1 & 0xffc7 | 0x30;
            goto _L32;
          }
          if (uVar1 != 2) goto _L31;
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar1 = *(ushort *)(iVar4 + iVar2);
          iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar2 + iVar4) = uVar1 & 0xffc7 | 0x20;
        }
        pcVar5 = *(code **)(_r_ip_funcs_p + 0x904);
_L37:
        (*pcVar5)(0xff,pcVar5);
      }
      else {
        if (uVar1 == 6) {
_L32:
          pcVar5 = *(code **)(_r_ip_funcs_p + 0x6d0);
          goto _L37;
        }
_L31:
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (uVar6,uVar1,"sch_prog.c",0x130,*(code **)(_r_plf_funcs_p + 0xc));
      }
    }
    *pcVar3 = '\0';
  }
  return;
}

