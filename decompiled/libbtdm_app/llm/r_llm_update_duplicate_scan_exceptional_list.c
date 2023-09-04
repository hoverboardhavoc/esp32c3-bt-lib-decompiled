/*
 * Last changed at upstream commit 9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * https://github.com/espressif/esp32c3-bt-lib/commit/9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * Upstream date: 2023-09-04 20:35:54 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(3a1003fc)
 * Source: libbtdm_app -> llm.o -> r_llm_update_duplicate_scan_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_update_duplicate_scan_exceptional_list(int param_1,uint param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  size_t sVar6;
  
  if (param_1 != 1) {
    if (param_1 != 0) {
      if (param_1 != 2) {
        return 0xc;
      }
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
      *(uint *)(iVar3 + 0x28) = ~param_2 & *(uint *)(iVar3 + 0x28);
      if ((param_2 & 1) != 0) {
        llm_util_flush_list(iVar3 + 0x2c);
      }
      if ((param_2 & 2) == 0) {
        return 0;
      }
      llm_util_flush_list(iVar3 + 0x34);
      return 0;
    }
    if (param_3 == (void *)0x0) {
      return 0x12;
    }
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
    switch(param_2) {
    case 0:
      piVar4 = (int *)(iVar3 + 0x2c);
      sVar6 = 6;
      goto _L76;
    case 1:
      piVar4 = (int *)(iVar3 + 0x34);
      sVar6 = 4;
_L76:
      if (piVar4 == (int *)0x0) {
        return 0x12;
      }
      for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        iVar2 = memcmp(piVar4 + 1,param_3,sVar6);
        if (iVar2 == 0) {
          return 0;
        }
      }
      iVar2 = (**(code **)(_r_modules_funcs_p + 0x120))
                        (0xc,0,*(code **)(_r_modules_funcs_p + 0x120));
      if (iVar2 == 0) {
        return 7;
      }
      if (param_2 == 0) {
        memcpy((void *)(iVar2 + 4),param_3,6);
        (**(code **)(_r_modules_funcs_p + 0x4c))
                  (iVar3 + 0x2c,iVar2,*(code **)(_r_modules_funcs_p + 0x4c));
        uVar5 = *(uint *)(iVar3 + 0x28) | 1;
      }
      else {
        if (param_2 != 1) {
          return 0;
        }
        memcpy((void *)(iVar2 + 4),param_3,4);
        (**(code **)(_r_modules_funcs_p + 0x4c))
                  (iVar3 + 0x34,iVar2,*(code **)(_r_modules_funcs_p + 0x4c));
        uVar5 = *(uint *)(iVar3 + 0x28) | 2;
      }
      break;
    case 2:
      uVar5 = *(uint *)(iVar3 + 0x28) | 4;
      break;
    case 3:
      uVar5 = *(uint *)(iVar3 + 0x28) | 8;
      break;
    case 4:
      uVar5 = *(uint *)(iVar3 + 0x28) | 0x10;
      break;
    case 5:
      uVar5 = *(uint *)(iVar3 + 0x28) | 0x20;
      break;
    case 6:
      uVar5 = *(uint *)(iVar3 + 0x28) | 0x40;
      break;
    default:
      goto _L67;
    }
    *(uint *)(iVar3 + 0x28) = uVar5;
    return 0;
  }
  if (param_3 == (void *)0x0) {
    return 0x12;
  }
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  switch(param_2) {
  case 0:
    piVar4 = (int *)(iVar3 + 0x2c);
    sVar6 = 6;
    goto _L92;
  case 1:
    piVar4 = (int *)(iVar3 + 0x34);
    sVar6 = 4;
_L92:
    if (piVar4 == (int *)0x0) {
_L67:
      return 0x12;
    }
    for (piVar1 = (int *)*piVar4; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      iVar2 = memcmp(piVar1 + 1,param_3,sVar6);
      if (iVar2 == 0) {
        (**(code **)(_r_modules_funcs_p + 0x1c))
                  (piVar4,piVar1,*(code **)(_r_modules_funcs_p + 0x1c));
        (**(code **)(_r_modules_funcs_p + 0x110))(piVar1,*(code **)(_r_modules_funcs_p + 0x110));
        break;
      }
    }
    if (*(int *)(iVar3 + 0x2c) == 0) {
      *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & 0xfffffffe;
    }
    if (*(int *)(iVar3 + 0x34) != 0) {
      return 0;
    }
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xfffffffd;
    break;
  case 2:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xfffffffb;
    break;
  case 3:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xfffffff7;
    break;
  case 4:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xffffffef;
    break;
  case 5:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xffffffdf;
    break;
  case 6:
    uVar5 = *(uint *)(iVar3 + 0x28) & 0xffffffbf;
    break;
  default:
    goto _L67;
  }
  *(uint *)(iVar3 + 0x28) = uVar5;
  return 0;
}

