/*
 * Last changed at upstream commit 0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfac1b21ebc995e8e9aa040ab1ab29deee4f580
 * Upstream date: 2023-08-10 21:56:13 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(59725b5)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr_eco(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_s3;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar3 = false;
  if (iVar4 != 0) {
    bVar1 = *(uint *)(iVar4 + 100) < 0x20;
    bVar2 = g_adv_delay_dis == '\0';
    bVar3 = bVar1 && bVar2;
    if ((param_3 == 0) &&
       (pcVar5 = (char *)(**(code **)(_r_ip_funcs_p + 0x914))(*(code **)(_r_ip_funcs_p + 0x914)),
       *pcVar5 != '\0')) {
      *(int *)(pcVar5 + 0xc) = *(int *)(pcVar5 + 0xc) + 1;
    }
    if (bVar1 && bVar2) {
      g_adv_delay_dis = '\x01';
      unaff_s3 = *(undefined4 *)(iVar4 + 100);
      uVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar6 = uVar6 % 9;
      iVar7 = uVar6 << 1;
      if (*(char *)(iVar4 + 0x95) != '\0') {
        if (uVar6 == 0) {
          iVar7 = 1;
        }
        else if (uVar6 == 8) {
          iVar7 = 0xf;
        }
      }
      *(uint *)(iVar4 + 100) = (uint)(iVar7 + *(int *)(iVar4 + 100) * 2) >> 1;
    }
  }
  r_lld_adv_frm_isr(param_1,param_2,param_3);
  if (bVar3) {
    g_adv_delay_dis = '\0';
    *(undefined4 *)(iVar4 + 100) = unaff_s3;
  }
  return;
}

