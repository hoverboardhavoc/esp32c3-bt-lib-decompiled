/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_cmd_reject
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_cmd_reject(int param_1,undefined4 param_2,undefined1 param_3,undefined1 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  code *pcVar5;
  void *__s1;
  undefined2 auStack_22 [3];
  
  if (param_1 == 0) {
    pcVar5 = *(code **)(_r_modules_funcs_p + 200);
    uVar4 = 0x1101;
_L55:
    puVar3 = (undefined1 *)(*pcVar5)(uVar4,0,param_2,1,pcVar5);
    *puVar3 = param_3;
  }
  else {
    if (*(code **)(param_1 + 8) == (code *)0x0) {
      pcVar5 = *(code **)(_r_modules_funcs_p + 200);
      uVar4 = 0x1102;
      goto _L55;
    }
    if (*(char *)(param_1 + 2) < '\0') {
      uVar1 = (**(code **)(param_1 + 8))(0,0,auStack_22,0);
      uVar1 = uVar1 & 0xff;
    }
    else {
      uVar1 = (**(code **)(_r_modules_funcs_p + 0x18))
                        (0,0,auStack_22,0xffff,*(code **)(_r_modules_funcs_p + 0x18));
    }
    if (uVar1 != 0) {
      (**(code **)(_r_plf_funcs_p + 0xc))(param_2,"hci_tl.c",0x1bf,*(code **)(_r_plf_funcs_p + 0xc))
      ;
      return;
    }
    __s1 = *(void **)(param_1 + 8);
    iVar2 = memcmp(__s1,&_LC1,2);
    pcVar5 = *(code **)(_r_modules_funcs_p + 200);
    if (iVar2 == 0) {
      puVar3 = (undefined1 *)(*pcVar5)(0x1101,0,param_2);
      *puVar3 = param_3;
      puVar3[2] = *param_4;
      puVar3[3] = param_4[1];
    }
    else {
      iVar2 = memcmp(__s1,&_LC2,3);
      if (iVar2 == 0) {
        puVar3 = (undefined1 *)(*pcVar5)(0x1101,0,param_2,auStack_22[0]);
        *puVar3 = param_3;
        memcpy(puVar3 + 1,param_4,6);
        pcVar5 = *(code **)(_r_ip_funcs_p + 0x8c);
        goto _L56;
      }
      puVar3 = (undefined1 *)(*pcVar5)(0x1101,0,param_2,auStack_22[0]);
      *puVar3 = param_3;
    }
  }
  pcVar5 = *(code **)(_r_ip_funcs_p + 0x8c);
_L56:
  (*pcVar5)(puVar3,pcVar5);
  return;
}

