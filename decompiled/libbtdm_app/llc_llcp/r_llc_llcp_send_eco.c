/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_send_eco(uint param_1,byte *param_2,code *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort auStack_32 [7];
  
  bVar1 = *param_2;
  if (bVar1 == 0) {
    param_3 = llc_llcp_conn_update_ind_ack;
  }
  else if (bVar1 == 1) {
    param_3 = *(code **)(_r_ip_funcs_p + 0x8f4);
  }
  else if (bVar1 == 0x18) {
    param_3 = llc_llcp_phy_update_ind_ack;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar4 + 0x18) == '\0') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llc_llcp.c",0x1f5,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  else if (bVar1 == 6) {
    llc_enc_state._2_2_ = (ushort)(1 << (param_1 & 0x1f)) | llc_enc_state._2_2_;
  }
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  if (((param_2 != (byte *)0x0) && (iVar4 != 0)) && (*param_2 < 0x23)) {
    auStack_32[0] = *(ushort *)(llcp_pdu_handler + (uint)*param_2 * 0xc + 8);
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x120))
                      (auStack_32[0] + 0xc,2,*(code **)(_r_modules_funcs_p + 0x120));
    bVar1 = *param_2;
    *(code **)(iVar2 + 4) = param_3;
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x10))
                      (iVar2 + 9,param_2,auStack_32,0x30,
                       *(undefined4 *)(llcp_pdu_handler + (uint)bVar1 * 0xc + 4),
                       *(code **)(_r_modules_funcs_p + 0x10));
    if (iVar3 == 0) {
      *(char *)(iVar2 + 8) = (char)auStack_32[0];
      (**(code **)(_r_modules_funcs_p + 0x44))
                (iVar4 + 0x28,iVar2,*(code **)(_r_modules_funcs_p + 0x44));
      (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1,*(code **)(_r_ip_funcs_p + 0x5b8));
    }
    else {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*param_2,"llc_llcp.c",0x33b,*(code **)(_r_plf_funcs_p + 0xc));
    }
    return;
  }
  if (param_2 == (byte *)0x0) {
    uVar5 = 0xffff;
  }
  else {
    uVar5 = (uint)*param_2;
  }
                    /* WARNING: Could not recover jumptable at 0x0001064c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))
            (param_1,uVar5,"llc_llcp.c",0x351,*(code **)(_r_plf_funcs_p + 0xc));
  return;
}

