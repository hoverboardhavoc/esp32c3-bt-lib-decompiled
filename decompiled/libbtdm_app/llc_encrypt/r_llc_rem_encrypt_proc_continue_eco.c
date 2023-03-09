/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llc_encrypt.o -> r_llc_rem_encrypt_proc_continue_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_rem_encrypt_proc_continue_eco(uint param_1,int param_2,int param_3)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(1,*(code **)(_r_ip_funcs_p + 0x674));
  puVar2 = (ushort *)(**(code **)(_r_ip_funcs_p + 0x910))(*(code **)(_r_ip_funcs_p + 0x910));
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar3 == param_2) {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar3 == 0x10) {
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,1,0,*(code **)(_r_ip_funcs_p + 0x68c));
      (**(code **)(_r_ip_funcs_p + 0x3bc))(param_1,1,*(code **)(_r_ip_funcs_p + 0x3bc));
      llc_ll_start_enc_rsp_pdu_send(param_1,0);
      *puVar2 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar2;
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((param_1 < *(byte *)(iVar3 + 0xd)) &&
          (iVar3 = *(int *)(&llc_env + param_1 * 4), iVar3 != 0)) &&
         ((*(byte *)(iVar3 + 0x44) & 3) != 3)) {
        (**(code **)(_r_ip_funcs_p + 0x328))(param_1,1,*(code **)(_r_ip_funcs_p + 0x328));
        (**(code **)(_r_ip_funcs_p + 0x664))(param_1,2,0,*(code **)(_r_ip_funcs_p + 0x664));
        if ((param_3 == 0) || (*(char *)(iVar1 + 0x3a) != '\0')) {
          (**(code **)(_r_ip_funcs_p + 0x57c))(param_1,param_3,*(code **)(_r_ip_funcs_p + 0x57c));
        }
        iVar1 = _r_ip_funcs_p;
        *(ushort *)(iVar4 + 0x42) = (ushort)(param_3 == 0) << 5 | *(ushort *)(iVar4 + 0x42) & 0xffdf
        ;
        (**(code **)(iVar1 + 0x610))(param_1,*(code **)(iVar1 + 0x610));
        (**(code **)(_r_ip_funcs_p + 0x688))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x688));
      }
      (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
      *(ushort *)(iVar4 + 0x42) = *(ushort *)(iVar4 + 0x42) & 0xfdff;
      return;
    }
    if (iVar3 != 0x12) goto _L3;
  }
  *puVar2 = ~(ushort)(1 << (param_1 & 0x1f)) & *puVar2;
_L3:
  r_llc_rem_encrypt_proc_continue(param_1,param_2,param_3);
  return;
}

