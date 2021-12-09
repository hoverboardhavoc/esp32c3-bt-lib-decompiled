/*
 * Last changed at upstream commit f9ffd57d8f829cc9079d9c51da6886844eee94d0
 * https://github.com/espressif/esp32c3-bt-lib/commit/f9ffd57d8f829cc9079d9c51da6886844eee94d0
 * Upstream date: 2021-12-09 12:38:22 +0530
 * Upstream subject: Fixing scenario where ACL Rx data is sent to host before enc change event [19bdc26c].
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_rem_encrypt_proc_continue_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_encrypt_proc_continue_hack(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar2 == param_2) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar2 == 0x10) {
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3bc));
      llc_ll_start_enc_rsp_pdu_send(param_1,0);
      enc_resp_recvd_slave = ~(byte)(1 << (param_1 & 0x1f)) & enc_resp_recvd_slave;
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((param_1 < *(byte *)(iVar2 + 0xd)) &&
          (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0)) &&
         ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
        (**(code **)(_r_ip_funcs_p + 0x328))(param_1,1,*(code **)(_r_ip_funcs_p + 0x328));
        (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,0,*(code **)(_r_ip_funcs_p + 0x664));
        if ((param_3 == 0) || (*(char *)(iVar1 + 0x3a) != '\0')) {
          (**(code **)(_r_ip_funcs_p + 0x57c))(param_1,param_3,*(code **)(_r_ip_funcs_p + 0x57c));
        }
        iVar1 = _r_ip_funcs_p;
        *(ushort *)(iVar3 + 0x42) = (ushort)(param_3 == 0) << 5 | *(ushort *)(iVar3 + 0x42) & 0xffdf
        ;
        (**(code **)(iVar1 + 0x610))(param_1,*(code **)(iVar1 + 0x610));
        (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x688));
      }
      (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
      *(ushort *)(iVar3 + 0x42) = *(ushort *)(iVar3 + 0x42) & 0xfdff;
      return;
    }
    if (iVar2 != 0x12) goto _L3;
  }
  enc_resp_recvd_slave = ~(byte)(1 << (param_1 & 0x1f)) & enc_resp_recvd_slave;
_L3:
  r_llc_rem_encrypt_proc_continue(param_1,param_2,param_3);
  return;
}

