/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_skip_isr(uint param_1,int param_2)

{
  char cVar1;
  code *UNRECOVERED_JUMPTABLE_00;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 == 0) {
    uVar4 = 0xb35;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
_L989:
                    /* WARNING: Could not recover jumptable at 0x00014c10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(0,"lld_adv.c",uVar4);
    return;
  }
  if (1 < (byte)(*(char *)(iVar2 + 0x89) - 1U)) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xaea,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(char *)(iVar2 + 0x89) == '\x02') {
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
    uVar4 = 0;
  }
  else {
    if ((*(char *)(iVar2 + 0x95) == '\0') || (*(int *)(iVar2 + 0x38) != param_2)) {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,1);
      if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
        if ((uint)(*(int *)(iVar2 + 100) << 1) <= (param_2 - *(int *)(iVar2 + 0x5c) & 0xfffffffU)) {
          *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
          *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(iVar2 + 4);
        }
      }
      else {
        *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
      }
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar2,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar3 == 0) goto _L982;
      if (*(char *)(iVar2 + 0x95) != '\0') {
        return;
      }
      if (*(int *)(iVar2 + 0x58) == -1) {
        uVar4 = 0xb29;
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
        goto _L989;
      }
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2 + 0x34,1);
      cVar1 = rwip_priority;
      if ((uint)(*(int *)(iVar2 + 100) << 1) <= (param_2 - *(int *)(iVar2 + 0x60) & 0xfffffffU)) {
        *(int *)(iVar2 + 0x60) = param_2;
        *(char *)(iVar2 + 0x4a) = *(char *)(iVar2 + 0x4a) + cVar1;
      }
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar2 + 0x34,*(code **)(_r_ip_funcs_p + 0x6b0));
      if (iVar3 == 0) {
_L982:
        *(undefined1 *)(iVar2 + 0x89) = 0;
        return;
      }
      if (*(int *)(iVar2 + 0x58) == -1) {
        uVar4 = 0xb07;
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 8);
        goto _L989;
      }
    }
    uVar4 = 0x3c;
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_ip_funcs_p + 0x1a0);
    param_1 = (uint)*(byte *)(iVar2 + 0x87);
  }
                    /* WARNING: Could not recover jumptable at 0x00014b78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1,1,uVar4);
  return;
}

