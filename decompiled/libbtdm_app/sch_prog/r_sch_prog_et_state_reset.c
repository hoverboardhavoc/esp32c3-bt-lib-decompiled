/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app -> sch_prog.o -> r_sch_prog_et_state_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_et_state_reset(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  ushort uVar4;
  code *pcVar5;
  uint uVar6;
  
  pcVar2 = (char *)(**(code **)(_r_ip_funcs_p + 0x920))(*(code **)(_r_ip_funcs_p + 0x920));
  if (*pcVar2 != '\0') {
    while (DAT_00011106 != '\0') {
      uVar6 = (uint)DAT_00011104;
      iVar1 = uVar6 * 0x10;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar3 + iVar1) >> 3 & 7;
      if (1 < _g_bt_plf_log_level) {
        iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
        ets_printf("et:%d,st:%x\n",uVar6,*(ushort *)(iVar3 + iVar1) >> 3 & 7);
      }
      if (uVar4 < 6) {
        if (uVar4 < 3) {
          if (uVar4 != 2) {
            iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar4 = *(ushort *)(iVar3 + iVar1);
            iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
            *(ushort *)(iVar3 + iVar1) = uVar4 & 0xffc7 | 0x30;
            goto _L30;
          }
          iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar4 = *(ushort *)(iVar3 + iVar1);
          iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar1 + iVar3) = uVar4 & 0xffc7 | 0x20;
        }
        pcVar5 = *(code **)(_r_ip_funcs_p + 0x904);
_L38:
        (*pcVar5)(0xff,pcVar5);
      }
      else {
        if (uVar4 == 6) {
_L30:
          pcVar5 = *(code **)(_r_ip_funcs_p + 0x6d0);
          goto _L38;
        }
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (uVar6,7,"sch_prog.c",0x132,*(code **)(_r_plf_funcs_p + 0xc));
      }
    }
    *pcVar2 = '\0';
  }
  return;
}

