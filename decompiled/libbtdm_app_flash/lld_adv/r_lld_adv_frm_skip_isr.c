/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_skip_isr(uint param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar5 = 0xb39;
_L986:
    r_assert_err(0,"lld_adv.c",uVar5);
    return;
  }
  if (1 < (byte)(*(char *)(iVar1 + 0x89) - 1U)) {
    r_assert_err(0,"lld_adv.c",0xaee);
  }
  if (*(char *)(iVar1 + 0x89) == '\x02') {
    cVar4 = '\0';
  }
  else {
    if ((*(char *)(iVar1 + 0x95) == '\0') || (*(int *)(iVar1 + 0x38) != param_2)) {
      r_sch_arb_remove(iVar1,1);
      if ((*(ushort *)(iVar1 + 0x74) & 8) == 0) {
        if ((uint)(*(int *)(iVar1 + 100) << 1) <= (param_2 - *(int *)(iVar1 + 0x5c) & 0xfffffffU)) {
          *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + rwip_priority;
          *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(iVar1 + 4);
        }
      }
      else {
        *(char *)(iVar1 + 0x16) = *(char *)(iVar1 + 0x16) + rwip_priority;
      }
      iVar3 = r_sch_arb_insert(iVar1);
      if (iVar3 == 0) goto _L979;
      if (*(char *)(iVar1 + 0x95) != '\0') {
        return;
      }
      if (*(int *)(iVar1 + 0x58) == -1) {
        uVar5 = 0xb2d;
        goto _L986;
      }
    }
    else {
      r_sch_arb_remove(iVar1 + 0x34,1);
      cVar4 = rwip_priority;
      if ((uint)(*(int *)(iVar1 + 100) << 1) <= (param_2 - *(int *)(iVar1 + 0x60) & 0xfffffffU)) {
        *(int *)(iVar1 + 0x60) = param_2;
        *(char *)(iVar1 + 0x4a) = *(char *)(iVar1 + 0x4a) + cVar4;
      }
      iVar3 = r_sch_arb_insert(iVar1 + 0x34);
      if (iVar3 == 0) {
_L979:
        *(undefined1 *)(iVar1 + 0x89) = 0;
        return;
      }
      if (*(int *)(iVar1 + 0x58) == -1) {
        uVar5 = 0xb0b;
        goto _L986;
      }
    }
    cVar4 = '<';
    param_1 = (uint)*(byte *)(iVar1 + 0x87);
  }
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    if ((((*(short *)(iVar1 + 0x24) != 0) && (*(short *)(iVar1 + 0x7e) != 0)) &&
        (*(short *)(iVar1 + 0x24) != *(short *)(iVar1 + 0x7e))) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar3 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar1 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar1 + 0x7e));
      }
    }
    if (((*(short *)(iVar1 + 0x26) != 0) && (*(short *)(iVar1 + 0x80) != 0)) &&
       ((*(short *)(iVar1 + 0x26) != *(short *)(iVar1 + 0x80) &&
        (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
       )) {
      iVar3 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar3 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar1 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar1 + 0x80));
      }
    }
  }
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    r_sch_arb_remove(iVar1,0);
    if (*(char *)(iVar1 + 0x95) != '\0') {
      r_sch_arb_remove(iVar1 + 0x34,0);
    }
    if ((*(ushort *)(iVar1 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
    *puVar2 = (char)param_1;
    puVar2[1] = cVar4;
    puVar2[0x35] = 0;
    if ((cVar4 != '\0') && (cVar4 = '\0', *(short *)(iVar1 + 0x78) != 0)) {
      cVar4 = *(char *)(iVar1 + 0x86);
    }
    puVar2[0x38] = cVar4;
    r_ke_msg_send();
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

