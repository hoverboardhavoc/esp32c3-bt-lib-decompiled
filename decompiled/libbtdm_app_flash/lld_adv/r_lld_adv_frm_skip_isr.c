/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_skip_isr(uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 == 0) {
    uVar6 = 0xb50;
_L1050:
    r_assert_err(0,"lld_adv.c",uVar6);
    return;
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 4) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x4040000a,(uint)*(byte *)(iVar2 + 0x89) << 8 | param_1,param_2);
  }
  if (1 < (byte)(*(char *)(iVar2 + 0x89) - 1U)) {
    r_assert_err(0,"lld_adv.c",0xb05);
  }
  if (*(char *)(iVar2 + 0x89) == '\x02') {
    uVar5 = 0;
  }
  else {
    if ((*(char *)(iVar2 + 0x95) == '\0') || (*(int *)(iVar2 + 0x38) != param_2)) {
      r_sch_arb_remove(iVar2,1);
      if ((*(ushort *)(iVar2 + 0x74) & 8) == 0) {
        if ((uint)(*(int *)(iVar2 + 100) << 1) <= (param_2 - *(int *)(iVar2 + 0x5c) & 0xfffffffU)) {
          *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
          *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(iVar2 + 4);
        }
      }
      else {
        *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
      }
      iVar4 = r_sch_arb_insert(iVar2);
      if (iVar4 == 0) goto _L1043;
      if (*(char *)(iVar2 + 0x95) != '\0') {
        return;
      }
      if (*(int *)(iVar2 + 0x58) == -1) {
        uVar6 = 0xb44;
        goto _L1050;
      }
    }
    else {
      r_sch_arb_remove(iVar2 + 0x34,1);
      cVar1 = rwip_priority;
      if ((uint)(*(int *)(iVar2 + 100) << 1) <= (param_2 - *(int *)(iVar2 + 0x60) & 0xfffffffU)) {
        *(int *)(iVar2 + 0x60) = param_2;
        *(char *)(iVar2 + 0x4a) = *(char *)(iVar2 + 0x4a) + cVar1;
      }
      iVar4 = r_sch_arb_insert(iVar2 + 0x34);
      if (iVar4 == 0) {
_L1043:
        *(undefined1 *)(iVar2 + 0x89) = 0;
        return;
      }
      if (*(int *)(iVar2 + 0x58) == -1) {
        uVar6 = 0xb22;
        goto _L1050;
      }
    }
    uVar5 = 0x3c;
    param_1 = (uint)*(byte *)(iVar2 + 0x87);
  }
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar4 + 0x28) & 4) != 0) &&
       (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40000002,(uint)*(byte *)(iVar2 + 0x89) << 0x18 | uVar5 << 0x10 | 0x100 | param_1)
      ;
    }
    if ((((*(short *)(iVar2 + 0x24) != 0) && (*(short *)(iVar2 + 0x7e) != 0)) &&
        (*(short *)(iVar2 + 0x24) != *(short *)(iVar2 + 0x7e))) &&
       (((*(ushort *)(iVar2 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10))))
    {
      iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar4 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar2 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar2 + 0x7e));
      }
    }
    if (((*(short *)(iVar2 + 0x26) != 0) && (*(short *)(iVar2 + 0x80) != 0)) &&
       ((*(short *)(iVar2 + 0x26) != *(short *)(iVar2 + 0x80) &&
        (((*(ushort *)(iVar2 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar2 + 0x74) & 0x14) == 0x10))))
       )) {
      iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar4 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar2 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar2 + 0x80));
      }
    }
  }
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar2 != 0) {
    r_sch_arb_remove(iVar2,0);
    if (*(char *)(iVar2 + 0x95) != '\0') {
      r_sch_arb_remove(iVar2 + 0x34,0);
    }
    if ((*(ushort *)(iVar2 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    puVar3 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
    *puVar3 = (char)param_1;
    puVar3[1] = (char)uVar5;
    puVar3[0x35] = 0;
    if ((uVar5 != 0) && (uVar5 = 0, *(short *)(iVar2 + 0x78) != 0)) {
      uVar5 = (uint)*(byte *)(iVar2 + 0x86);
    }
    puVar3[0x38] = (char)uVar5;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

